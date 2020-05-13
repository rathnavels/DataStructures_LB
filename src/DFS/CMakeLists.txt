cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(DFS)


set(SOURCE
	main.cpp
	decodeString.cpp
	)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})