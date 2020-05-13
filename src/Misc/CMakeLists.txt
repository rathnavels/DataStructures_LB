cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE ON)

project(Misc)


set(SOURCE
	main.cpp
	atoi.cpp
	Template.cpp
	MatrixSpiral.cpp
	PetrolPump.cpp
	RainWater.cpp
	LRUCache.cpp)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})