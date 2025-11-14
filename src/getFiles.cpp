#include <iostream>
#include <fstream>
#include <filesystem>

#include "getFiles.h"
#include "platform.h"

class OpenMyFile : public std::fstream{
    private :
        std::filesystem::path mPath;
        std::ios_base::openmode mOpenMode;
    public:
        OpenMyFile(std::filesystem::path _myPath, std::ios_base::openmode _openMode) 
            : std::fstream (_myPath,_openMode) {
            mPath = _myPath;
            mOpenMode = _openMode;
        }
        virtual ~OpenMyFile(){
            if(this->is_open()){
                this->close();
            }
        }
        OpenMyFile* operator()(){
            *this << "ătest 2\n";
            *this << "testă 1\n";
            return this;
        }

};

void getFiles::FDemo() {
	//std::filesystem::path myPath("/mnt/c/dorin_excel_data/tablete/alte fisiere");
#ifdef OS_WIN
	//std::filesystem::path myPath("C:\\dorin_excel_data\\");
        auto moviesDir = std::filesystem::path("C:/Users/Dorin/Desktop/torrents/").make_preferred();
        auto TVShowsDir = std::filesystem::path ("/c/Users/Dorin/Desktop/torrents/seriale/").make_preferred();
	//std::filesystem::path myPath(u8"C:\\Users\\dorin\\Desktop\\imprimare\\");
#elif OS_LINUX
	std::filesystem::path myPath("/mnt/c/dorin_excel_data/tablete/alte fisiere");
#endif // OS_*

        //open a file and write something
	std::filesystem::path _myFilePath = std::filesystem::path(moviesDir.string()).append("test.txt");
        _myFilePath.make_preferred();
        OpenMyFile myFile(_myFilePath, std::ios_base::out | std::ios_base::binary);
	//OpenMyFile myFile ( _myFilepath, std::ios_base::binary) ;

	const char* const localname = "ro_RO.utf-8";
	std::cout << "std::setlocale = " << std::setlocale(LC_ALL, localname) <<std::endl ;
	std::locale::global (std::locale(localname));
	//std::cout << "my LANG " << std::getenv("LANG"); //bug in windows, crash
#ifdef OS_WIN
	if(std::FILE* f =_wfopen(_myFilePath.c_str(),L"r")) 
#elif OS_LINUX
        if(std::FILE *f = fopen (_myFile.c_str(),'r')) 
#endif
        { //if "_myFilePath" file is opened
            for (auto const& dir_entry : std::filesystem::recursive_directory_iterator(moviesDir,std::filesystem::directory_options::skip_permission_denied) ){
                    std::cout << std::quoted(dir_entry.path().string());
                    //std::wcout << (dir_entry.is_directory()?(std::filesystem::path::preferred_separator):std::wstring() )<<std::endl;
                    if(dir_entry.is_directory()){
                        std::wcout<<std::filesystem::path::preferred_separator<<std::endl;
                    }else std::cout<<std::endl;
                    //std::wcout <<std::filesystem::path::preferred_separator << "<-  preferred_separator \n ";
                    //myFile << dir_entry.path().string() << '\n';
            }
            myFile.close();

            std::cout << "in file \n";
            for (int ch; (ch = fgetc(f)) !=EOF; std::putchar(ch)){}
            std::fclose(f);
	} else std::cout <<"could not open file\n";
	std::cout <<"Apasa ENTER pt a continua"; std::cin.get();
	std::cout << "my file is : " << _myFilePath.make_preferred() <<std::endl;
	//std::filesystem::remove(myFile);
}

