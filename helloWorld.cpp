#include <iostream>

#include <fstream>
#include <filesystem>

//dont show console
#ifdef _MSC_VER
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif
//#include <cstdio>
/*

//#include <fcntl.h>
//#include <io.h>

#include <windows.h>
//set console output for windows to utf-8. i need a variable to run function outside maine...
const BOOL  &x =SetConsoleOutputCP(65001);
#endif 

*/

#include <getLanguage.h>
#include <GUIDisplay.h>

// filesystem demo
void FDemo() {
	std::cout << "Hello World"<< std::endl;
	//std::filesystem::path myPath("C:\\Users\\dorin\\Desktop");
	//std::filesystem::path myPath("/mnt/c/dorin_excel_data/tablete/alte fisiere");
	std::filesystem::path myPath(u8"C:/dorin_excel_data/");
	const std::filesystem::path _myFile (myPath.string() + "/myFile.txt");
	std::ofstream myFile ( _myFile, std::ios_base::binary) ;
	myFile << "test 2\n";
	myFile << "test 1\n";
	//std::setlocale(LC_ALL, localname);
	//ro_RO.utf-8
	//const char* const localname = "ro_RO.utf-8";
	const char* const localname = "en_EN.utf-8";
	std::cout << "std::setlocale = " << std::setlocale(LC_ALL, localname) <<std::endl ;
	std::locale::global (std::locale(localname));
	std::cout << "my LANG " << std::getenv("LANG");
#ifdef _MSC_VER
	//_setmode(_fileno(stderr), _O_WTEXT);
#else
	std::setlocale(LC_ALL,"");
	std::locale::global (std::locale(""));
#endif

	/*open another file and test
	 * its temp
	 */
#ifdef _MSC_VER
	if(std::FILE* f =_wfopen(_myFile.c_str(),L"r"))

#endif
	{
		for (auto const& dir_entry : std::filesystem::recursive_directory_iterator(myPath,std::filesystem::directory_options::skip_permission_denied) ){
			std::cout << dir_entry.path().string()<< "\n";
			//myFile << dir_entry.path().string();
		}
		myFile.close();

		std::cout << "in file \n";
		for (int ch; (ch = fgetc(f)) !=EOF; std::putchar(ch)){}
		std::fclose(f);
	}
	std::cout <<"Apasa ENTER pt a continua\n"; std::cin.get();
	std::cout << "my file is : " << _myFile <<std::endl;
	//std::filesystem::remove(myFile);
}


int main (int argc , char **argv) {
	get_language();
	FL::gui_window();
	//display::MessageBoxi();
	//FDemo();
	//std::cout <<"ENTER to exit:";
	//std::getchar();
	return 0;
}
