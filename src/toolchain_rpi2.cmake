set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_SYSROOT /home/sergey/raspi/sysroot)
set(qt5_lib_cmake /home/sergey/raspi/qt5pi/lib/cmake)
set(tools /home/sergey/raspi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64)

set(CMAKE_C_COMPILER ${tools}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${tools}/bin/arm-linux-gnueabihf-g++)

set(Qt5Core_DIR ${qt5_lib_cmake}/Qt5Core)
set(Qt5Gui_DIR ${qt5_lib_cmake}/Qt5Gui)
set(Qt5Widgets_DIR ${qt5_lib_cmake}/Qt5Widgets)
set(Qt5Network_DIR ${qt5_lib_cmake}/Qt5Network)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)


