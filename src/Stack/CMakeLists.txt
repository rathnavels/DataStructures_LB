cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Stack)


set(SOURCE
	main.cpp
	NGEStack.cpp
	StackSequence.cpp
	InfixToPostfix.cpp
	QueueUsingStack.cpp
	PostFix.cpp
	DeleteMiddleElement.cpp
	ReverseStackRecursion.cpp
	SortStackRecursion.cpp
	DynamicStack.cpp)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})