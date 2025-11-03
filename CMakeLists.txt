cmake_minimum_required (VERSION 4.0.3)

set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED True)
set (MY_PROJECT_NAME Hello)

# set output
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
project ("${MY_PROJECT_NAME}")

add_executable ("${MY_PROJECT_NAME}" helloWorld.cpp)
add_subdirectory (FLTK)

#target_link_directories( "${MY_PROJECT_NAME}"
#       	PUBLIC 
#	   lib
#)

target_link_libraries("${MY_PROJECT_NAME}" 
	fltk
)

target_include_directories("${MY_PROJECT_NAME}" PUBLIC
#			   "${PROJECT_SOURCE_DIR}/myFunc"
			   "${PROJECT_SOURCE_DIR}/FLTK"
			   #add FLTK costum config.h file
			   "${PROJECT_BINARY_DIR}/FLTK"
)



