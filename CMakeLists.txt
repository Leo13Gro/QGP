cmake_minimum_required(VERSION 3.27)
project(QGP)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED)

include(${ROOT_USE_FILE})
include_directories(
        ${CMAKE_SOURCE_DIR}
        ${ROOT_INCLUDE_DIRS}
)

add_executable(QGP main.cpp createDf.cpp)
