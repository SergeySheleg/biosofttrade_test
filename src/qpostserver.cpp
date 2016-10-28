#include <QTcpSocket>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <iostream>

#include <string>
#include <sstream>
#include "qpostserver.h"


QPostServer::QPostServer(QObject *parent) : QObject(parent) {
    m_qTcpServer = new QTcpServer(this);

    connect(m_qTcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if (!m_qTcpServer->listen(QHostAddress::Any, 8080)) {
        qDebug() << "Server could not start";
        m_qTcpServer->close();
    } else {
        qDebug() << "Server started!";
    }
}

QPostServer::~QPostServer() {
    if (m_qTcpServer != nullptr) {
        m_qTcpServer->close();
    }
}

void QPostServer::newConnection() {
    if (m_acceptedSocket != nullptr) {
        qDebug() << "Attempt connect when connect";
        QTcpSocket *tempSocket = m_qTcpServer->nextPendingConnection();
        tempSocket->close();
    } else {
        qDebug() << "Connect";
        m_acceptedSocket = m_qTcpServer->nextPendingConnection();
        setKeepAliveOptions();
        connect(m_acceptedSocket, SIGNAL(readyRead()), this, SLOT(acceptedSocketReadyRead()));
        connect(m_acceptedSocket, SIGNAL(disconnected()), this, SLOT(acceptedSocketDisconnect()));
    }
}

void QPostServer::acceptedSocketDisconnect() {
    if (m_acceptedSocket != nullptr) {
        m_acceptedSocket->close();
        disconnect(m_acceptedSocket, SIGNAL(readyRead()), 0, 0);
        disconnect(m_acceptedSocket, SIGNAL(disconnected()), 0, 0);
        m_acceptedSocket = nullptr;
        qDebug() << "Disconnect";
    }
}

void QPostServer::acceptedSocketReadyRead() {
    if (m_acceptedSocket != nullptr) {
        auto data = m_acceptedSocket->readAll();
        std::cerr << data.data() << std::endl;

        std::map<std::string, std::string> httpHeader;

        std::istringstream iss(data.data());

        size_t payloadOffset = iss.str().find("\r\n\r\n");
        if (payloadOffset == std::string::npos) {
            return;
        }

        std::string httpMethod; iss >> httpMethod;
        if (httpMethod != "POST") {
            return;
        }

        std::string httpPath; iss >> httpPath;
        std::string httpProtocol; iss >> httpProtocol;

        std::string httpParamName;
        std::string httpParamValue;
        while (iss.rdbuf()->in_avail() && (size_t)iss.tellg() != payloadOffset) {
            iss >> httpParamName;
            iss >> httpParamValue;
            httpHeader.emplace(httpParamName, httpParamValue);
            httpParamName.clear();
            httpParamValue.clear();
        }
        iss.seekg(payloadOffset + 4);

        if (httpHeader["Content-Type:"] == "application/x-www-form-urlencoded") {
            std::map<std::string, std::string> httpPayload;
            std::string option;
            while (std::getline(iss, option, '&')) {
                httpPayload.emplace(option.substr(0, option.find('=')), option.substr(option.find('=') + 1));
            }
            emit newFormShowSignal(httpPayload["form"]);
        }
    }
}

void QPostServer::setKeepAliveOptions() {
    int fd = m_acceptedSocket->socketDescriptor();
    int enableKeepAlive = 1;
    int maxIdle = 15;
    int count = 3;
    int interval = 10;

    setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &enableKeepAlive, sizeof(enableKeepAlive));
    setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &maxIdle, sizeof(maxIdle));
    setsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT, &count, sizeof(count));
    setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &interval, sizeof(interval));
}
