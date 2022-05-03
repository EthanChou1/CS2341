cmake_minimum_required(VERSION 3.15)
project(22s_flight_planner)

set(CMAKE_CXX_STANDARD 14)

configure_file(data/sample01-flight-data.txt data/sample01-flight-data.txt COPYONLY)
configure_file(data/sample01-req-flights.txt data/sample01-req-flights.txt COPYONLY)

add_executable(22s_flight_planner main.cpp catch_setup.cpp sample_tests.cpp DSLinkedList.h DSString.h DSString.cpp DSStringTest.cpp DSVector.h DSVectorTests.cpp Airport.cpp Airport.h DSStack.h LinkedListAndStackTest.cpp DSAdjacencyList.cpp DSAdjacencyList.h Route.cpp Route.h)
