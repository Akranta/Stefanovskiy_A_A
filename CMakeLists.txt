cmake_minimum_required(VERSION 2.8)
									
project(bor)

set(SOURCE_EXE ptree.cpp)			

include_directories(trie)		

add_executable(ptree ${SOURCE_EXE})	

add_subdirectory(trie)				
target_link_libraries(ptree trie)	