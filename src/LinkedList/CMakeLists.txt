cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(LinkedList)


set(SOURCE
	main.cpp
	List.cpp
	LCHard25.cpp
	LCHard23.cpp)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})