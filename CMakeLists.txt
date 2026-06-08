cmake_minimum_required(VERSION 3.20)

project(okayGo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hangman "hangMan/src/main.cpp" "hangMan/src/WordHelper.cpp")


target_include_directories(hangman PRIVATE ${CMAKE_SOURCE_DIR}/hangman ${CMAKE_SOURCE_DIR}/hangman/include)
file(COPY ${CMAKE_SOURCE_DIR}/hangman/resources DESTINATION ${CMAKE_BINARY_DIR})