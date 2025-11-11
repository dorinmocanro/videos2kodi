add_library(displayMessage GUIDisplay.cpp) 
add_library(getLanguage getLanguage.cpp)
target_include_directories(displayMessage PUBLIC
	"${PROJECT_SOURCE_DIR}/FLTK"
	#also the custom config for fltk
	"${PROJECT_BINARY_DIR}/FLTK"
)
message ("hello")
message ("${PROJECT_SOURCE_DIR}/src")
message ("---------------")
