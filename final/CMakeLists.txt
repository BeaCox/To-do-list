cmake_minimum_required(VERSION 3.10.2)

project(tasktest)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(tasktest main.cpp task.cpp add_name2file.cpp EntryMD5.c deleteSpace.cpp)

target_link_libraries(tasktest pthread)
