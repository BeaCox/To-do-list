cmake_minimum_required(VERSION 3.10.2)

project(todo)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(todo main.cpp task.cpp add_name2file.cpp EntryMD5.c deleteSpace.cpp)

target_link_libraries(todo pthread)
