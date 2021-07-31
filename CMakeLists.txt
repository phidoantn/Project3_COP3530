cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(lol)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(lol main.cpp Screen.cpp Screen.h)
target_link_libraries(lol sfml-graphics sfml-audio)
