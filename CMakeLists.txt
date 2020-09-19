cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME Ptree)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
	src/ptree.cpp
	src/trie.cpp
	src/trie.h
)
