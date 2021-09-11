CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET(CMAKE_CXX_STANDARD 23)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fsanitize=address -g3")

PROJECT(taskmaster_ctl C CXX)

#FIND_PACKAGE(nlohmann_json 3.2.0 REQUIRED)

#TARGET_LINK_LIBRARIES(taskmaster_ctl PRIVATE nlohmann_json::nlohmann_json)

INCLUDE_DIRECTORIES(./includes)
file(GLOB SRCS "./srcs/*.cpp")

ADD_EXECUTABLE(taskmaster_ctl ${SRCS} includes/json.hpp srcs/json.cpp)