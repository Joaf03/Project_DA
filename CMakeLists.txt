cmake_minimum_required(VERSION 3.23)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled2 src/main.cpp src/WaterReservoir.h src/WaterReservoir.cpp src/PumpingStation.cpp src/PumpingStation.h src/DeliverySite.cpp src/DeliverySite.h src/Pipeline.cpp src/Pipeline.h src/Graph.cpp src/Graph.h src/DataLoader.cpp src/DataLoader.h)