cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Stack)


set(SOURCE
	main.cpp
	Template)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})