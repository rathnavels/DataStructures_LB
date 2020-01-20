cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Misc)


set(SOURCE
	main.cpp
	atoi.cpp
	Template.cpp)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})