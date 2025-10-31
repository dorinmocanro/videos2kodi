#include <iostream>
#include <filesystem>

#include <FL\Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>



// filesystem demo
//
void FDemo() {
	long unsigned size=0;
	std::cout << "Hello World"<< std::endl;
	std::filesystem::path myPath("C:\\Users\\dorin\\Desktop");
	myPath.make_preferred();
	std::wcout << "mypath= " << myPath.wstring() << std::endl;
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator(myPath) ){
		//std::cout<<dir_entry<<std::endl;
		++size;
	}

	//myFunc();
	std::cout << "elemente totale: " << size <<std::endl;
}


int main (){
	Fl_Window *window = new Fl_Window(340,180);
	Fl_Box *box = new Fl_Box(20,40,300,100,"Hello World");
	box -> box(FL_UP_BOX);
	box -> labelfont (FL_BOLD + FL_ITALIC);
	box -> labelsize (36);
	box -> labeltype (FL_SHADOW_LABEL);

	window -> end();
	window -> show();

	return Fl::run();

}
