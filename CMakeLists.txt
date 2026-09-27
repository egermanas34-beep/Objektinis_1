cmake_minimum_required(VERSION 3.10)

project(StudentuSistema)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "*.cpp")

add_executable(StudentuSistema ${SOURCES})

target_include_directories(StudentuSistema PRIVATE ${CMAKE_SOURCE_DIR})