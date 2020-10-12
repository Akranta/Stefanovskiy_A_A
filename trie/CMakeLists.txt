cmake_minimum_required(VERSION 2.8) 

project(trie)				

set(SOURCE_LIB trie.cpp)		

add_library(trie STATIC ${SOURCE_LIB})