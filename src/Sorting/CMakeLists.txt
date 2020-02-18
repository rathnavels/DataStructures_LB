cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Sorting)


set(SOURCE
	main.cpp
	RecursiveBubbleSort.cpp
	)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})