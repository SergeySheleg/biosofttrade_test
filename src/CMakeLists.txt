cmake_minimum_required(VERSION 3.5)

project(widgets_test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

add_executable(widgets_test main.cpp mainwindow.cpp clockform.cpp processingform.cpp actionchooseform.cpp accessdeniedform.cpp accessgrantedform.cpp qpostserver.cpp)

qt5_use_modules(widgets_test Core Gui Widgets Network)
