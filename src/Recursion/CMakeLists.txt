cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Recursion)


set(SOURCE
	main.cpp
	TowerOfHanoi.cpp
	)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})