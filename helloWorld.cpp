#include <iostream>
#include <filesystem>

#include <FL\Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>



// filesystem demo
void FDemo() {
	long unsigned size=0;
	std::cout << "Hello World"<< std::endl;
	//std::filesystem::path myPath("C:\\Users\\dorin\\Desktop");
	std::filesystem::path myPath("C:/dorin_excel_data/tablete/alte fisiere");
	
	const char* const localname = "ro-RO.utf-8";
	//std::setlocale(LC_ALL, localname);
	std::setlocale(LC_ALL, localname);
	std::locale::global (std::locale(localname));

	std::cout << "mypath= " << myPath.string() << std::endl;
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator(myPath,std::filesystem::directory_options::skip_permission_denied) ){
		std::cout<<dir_entry.path().string()<<std::endl;
		++size;
	}
	std::cout <<"caractere speciale \naăâî sș tț \n";
	std::cout << "elemente totale: " << size <<std::endl;
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
	gui_window();
	
	FDemo();
	auto my_lenght{3UZ};
	return 0;
}
