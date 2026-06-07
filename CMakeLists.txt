cmake_minimum_required(VERSION 3.20)

project(okayGo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(okayGo "src/main.cpp")
target_include_directories(okayGo PRIVATE ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/headers)