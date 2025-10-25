cmake_minimum_required (VERSION 4.0.3)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)

project (Hello)

add_executable (Hello helloWorld.cpp)
# add_subdirectory (myFunc)
target_link_directories( Hello
       	PUBLIC 
	   lib
)
target_link_libraries(Hello myfunc)

target_include_directories(Hello PUBLIC
			   "${PROJECT_SOURCE_DIR}/myFunc"
)

