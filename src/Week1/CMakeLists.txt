cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Week1)


set(SOURCE
	main.cpp
	SubArrayZero.cpp)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})