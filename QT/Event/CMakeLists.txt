cmake_minimum_required(VERSION 3.5)
project(ChownFile)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)

#Qt PrefixPath
#set(CMAKE_PREFIX_PATH /home/gaochong/Qt5.12.9/5.12.9/gcc_64)

set(SOURCE_FILES
        main.cpp
        MainWindow.cpp MainWindow.h)


#find_package(Qt5Core)
find_package(Qt5Widgets)
#find_package(Qt5Network)

add_executable(ChownFile ${SOURCE_FILES})

# Link Qt library
TARGET_LINK_LIBRARIES(ChownFile Qt5::Widgets crypto)
