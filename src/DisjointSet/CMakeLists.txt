cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(DisjointSet)


set(SOURCE
	main.cpp
	UnionFind101.cpp
	)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})