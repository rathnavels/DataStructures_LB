cmake_minimum_required(VERSION 3.6)

set (CMAKE_VERBOSE_MAKEFILE 1)


project(Graphs)


set(SOURCE
	main.cpp
	GraphDFS.cpp
	GraphWeightedDFS.cpp
	GraphBFS.cpp
	GraphUsingSet.cpp
	TopoSort.cpp
	StartToEnd.cpp
	DetectCycleDirected.cpp
	ShortestPathDirectedUW.cpp
	StringUsingGraph.cpp
	DetectCycleUnDirected.cpp
	Dijkstra.cpp
	Kruskals01.cpp
	)
	
	
add_executable(${PROJECT_NAME} ${SOURCE})