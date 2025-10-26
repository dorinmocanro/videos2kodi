cmake_minimum_required (VERSION 4.0.3)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)
set (MY_PROJECT_NAME Hello)
project ("${MY_PROJECT_NAME}")

add_executable ("${MY_PROJECT_NAME}" helloWorld.cpp)
# add_subdirectory (myFunc)
target_link_directories( "${MY_PROJECT_NAME}"
       	PUBLIC 
	   lib
)
target_link_libraries("${MY_PROJECT_NAME}" myfunc)

target_include_directories("${MY_PROJECT_NAME}" PUBLIC
			   "${PROJECT_SOURCE_DIR}/myFunc"
)



