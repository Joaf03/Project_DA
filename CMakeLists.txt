cmake_minimum_required(VERSION 3.27)
project(Project_DA)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Project_DA
        src/Graph.cpp
        src/Graph.h
        src/main.cpp
        src/menu.cpp
        src/Pipeline.cpp
        src/Pipeline.h
        src/waterNeeds.cpp
        src/waterNeeds.h)
