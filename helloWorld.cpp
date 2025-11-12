#include <iostream>

//dont show console
#ifdef _MSC_VER
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include "getLanguage.h"
#include "GUIDisplay.h"
#include "getFiles.h"
// filesystem demo

int main (int argc , char **argv) {
        std::wcout << "Languages: " << getLanguage();
        getFiles::FDemo();
	//FL::gui_window();

	//display::MessageBoxi();
	//std::cout <<"ENTER to exit:";
	//std::getchar();
	return 0;
}
