cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(ArrayBitManip)


set(SOURCE
	main.cpp
	SubArrayZeroBruteForce.cpp
	SubArrayZeroOptimized.cpp
	WaveArray.cpp
	PrintDuplicate.cpp
	Template.cpp
	MaxProductBurteForce.cpp
	MinSizeSubArray.cpp
	SwapThreeNum.cpp
	NumberofBits.cpp
	NextGreaterElement.cpp
	FlipBits.cpp)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})