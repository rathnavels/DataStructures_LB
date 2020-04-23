cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Heap)


set(SOURCE
	main.cpp
	MaxHeap.cpp
	)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})