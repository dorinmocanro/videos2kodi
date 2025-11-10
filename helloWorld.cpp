#include <iostream>

#include <fstream>
#include <filesystem>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
//#include <cstdio>
/*

#ifdef _MSC_VER
//#include <fcntl.h>
//#include <io.h>

#include <windows.h>
//set console output for windows to utf-8. i need a variable to run function outside maine...
const BOOL  &x =SetConsoleOutputCP(65001);
//#else
#endif 

//#include <clocale>
//#include <locale>
*/

/*
//if we run windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) ||defined (_MSC_VER) && !defined(__CYGWIN__)
#include <windows.h>
const BOOL  &x =SetConsoleOutputCP(65001);
#include <fcntl.h>
#include <io.h>
//if linux
#else 
#include <clocale>
#include <locale>
#endif 

#ifdef _MSC_VER
#include <fcntl.h>
#include <io.h>
#include <cstdio>
*/

//#include <cstdlib>
//#include <winnls.h>
//todo 
// get windows language
// GetUserPreferredUILanguages (DWORD ,PULONG
//
//
//
//
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


int gui_window(){
	Fl_Window *window = new Fl_Window(340,180);
	Fl_Box *box = new Fl_Box(20,40,300,100,"Hello aăî sș tț World");
	box -> box(FL_UP_BOX);
	box -> labelfont (FL_BOLD + FL_ITALIC);
	box -> labelsize (36);
	box -> labeltype (FL_SHADOW_LABEL);
	window -> end();
	window -> show();
	return Fl::run();
}


int main (int argc , char **argv) {
	//SetConsoleOutputCP(65001);
	////gui_window();
	//include GUIDisplay.h
	display::MessageBoxi();
	//FDemo();
	get_language();
	std::cout <<"ENTER to exit:";
	std::getchar();
	return 0;
}
