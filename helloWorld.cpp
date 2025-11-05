#include <iostream>
#include <fstream>
#include <filesystem>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <windows.h>
//#include <winuser.h>
#include <locale.h>

void myDisplay (){

	MessageBoxW(nullptr, L"Operation completed successfullyăâîșț.", L"Info", MB_OK | MB_ICONINFORMATION);
}


// filesystem demo
void FDemo() {
	std::cout << "Hello World"<< std::endl;
	//std::filesystem::path myPath("C:\\Users\\dorin\\Desktop");
	//std::filesystem::path myPath("/mnt/c/dorin_excel_data/tablete/alte fisiere");
	std::filesystem::path myPath("C:/dorin_excel_data/tablete/alte fisiere");
	std::ofstream myFile( myPath.string() + "/myFile.txt");	
	myFile << "test\n";
	//std::setlocale(LC_ALL, localname);
	//ro_RO.utf-8
	//const char* const localname = "ro_RO.utf-8";
	const char* const localname = "ro_RO.utf-8";
	std::cout << "std::setlocale = " << std::setlocale(LC_ALL, localname) <<std::endl ;
	std::locale::global (std::locale(localname));
	std::cout << "mypath= " << myPath.string() << std::endl;

	std::cout << "test string: aăîsștț\n";
	std::wcout <<"test string: aăîsștț\n";
	std::wcout <<L"test string: aăîsștț\n";
	std::cout <<"ăîțș\n";
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator(myPath,std::filesystem::directory_options::skip_permission_denied) ){
		std::cout<<dir_entry.path().string()<<std::endl;
		myFile << dir_entry.path().string() <<std::endl;
	}
	std::cout <<"caractere speciale \naăâî sș tțț \n";
	myFile.close();
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
	////gui_window();
	FDemo();
	myDisplay();
	return 0;
	}
