cmake_minimum_required (VERSION 3.22)

set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED True)
set (MY_PROJECT_NAME Hello)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# set output
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
project ("${MY_PROJECT_NAME}")

add_executable ("${MY_PROJECT_NAME}" helloWorld.cpp)
add_subdirectory (FLTK)
add_subdirectory (src)
#target_link_directories( "${MY_PROJECT_NAME}"
#       	PUBLIC 
#	   lib
#)

	
target_link_libraries("${MY_PROJECT_NAME}" 
	fltk
	getLanguage
	displayMessage
)

target_include_directories("${MY_PROJECT_NAME}" PUBLIC
#			   "${PROJECT_SOURCE_DIR}/myFunc"
			   "${PROJECT_SOURCE_DIR}/FLTK"
			   "${PROJECT_SOURCE_DIR}/src"
			   #add FLTK costum config.h file
			   "${PROJECT_BINARY_DIR}/FLTK"
)



