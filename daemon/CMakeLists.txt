CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET(CMAKE_CXX_STANDARD 23)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

PROJECT(taskmaster_daemon C CXX)

INCLUDE_DIRECTORIES(./includes)
file(GLOB SRCS "./srcs/*.cpp")

ADD_EXECUTABLE(taskmaster_daemon ${SRCS} srcs/TunnelTCP.cpp includes/TunnelTCP.hpp)