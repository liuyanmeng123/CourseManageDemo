cmake_minimum_required(VERSION 3.0)
project(CourseManage)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE PROJECT_SOURCES
        src/*.cpp
        src/*.h
        src/*.hpp
        )

add_executable(CourseManage ${PROJECT_SOURCES} src/student.cpp)

