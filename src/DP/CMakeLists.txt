cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(DP)


set(SOURCE
	main.cpp
	StringPermutations.cpp
	MinimumNoOfCoins.cpp
	LargestSumSubArray.cpp
	)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})