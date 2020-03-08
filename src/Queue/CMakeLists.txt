cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Queue)


set(SOURCE
	main.cpp
	StackUsingQueue.cpp
	ReverseQueueUsingStack.cpp
	)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})