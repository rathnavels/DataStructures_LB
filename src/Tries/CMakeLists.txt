cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Tries)


set(SOURCE
	main.cpp
	Trie01.cpp
	Trie02.cpp
	Trie03.cpp
	)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})