#ifndef QPOSTSERVER_H
#define QPOSTSERVER_H

#include <QObject>
#include <QTcpServer>

class QPostServer : public QObject {
    Q_OBJECT
private:
    QTcpServer *m_qTcpServer = nullptr;
    QTcpSocket *m_acceptedSocket = nullptr;

public:
    explicit QPostServer(QObject *parent = 0);
    ~QPostServer();

public slots:
    void newConnection();
    void acceptedSocketReadyRead();
    void acceptedSocketDisconnect();

signals:
    void newFormShowSignal(std::string);

private:
    void setKeepAliveOptions();
};

#endif // QPOSTSERVER_H
