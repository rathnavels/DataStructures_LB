cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Stack)


set(SOURCE
	main.cpp
	NGEStack.cpp
	Template)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})