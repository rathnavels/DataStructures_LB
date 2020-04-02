cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Graphs)


set(SOURCE
	main.cpp
	GraphDFS.cpp
	GraphWeightedDFS.cpp
	)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})