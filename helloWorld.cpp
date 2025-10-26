#include <iostream>
#include <myfunc.h>
#include <filesystem>
int main (){
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
	std::cout << "elemente totale: " <<std::endl;
}


