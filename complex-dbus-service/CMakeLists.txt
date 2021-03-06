cmake_minimum_required(VERSION 3.14)

project(complex-dbus-service VERSION 1.0.2 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core DBus REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core DBus REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        ../common/inc/customdata.h ../common/src/customdata.cpp
        complexinterface.cpp complexinterface.h
        complexAdaptor.cpp complexAdaptor.h)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ../common/inc)

target_link_libraries(${PROJECT_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Core
                                        Qt${QT_VERSION_MAJOR}::DBus)
