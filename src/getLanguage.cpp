#include <iostream>
#include <vector>
#include <string>



//#include <clocale>
//#include <locale>
//#include <cstdlib>
//#include <winnls.h>

#include "getLanguage.h"
#include "platform.h"

#ifdef OS_WIN 
#include <windows.h>
const bool &x = SetConsoleOutputCP(65001);

std::wstring getLanguage(){
	DWORD flags = MUI_LANGUAGE_NAME,buffLenght = 0;
	ULONG langs = 0 ;
	PZZWSTR ptrLang;
	PULONG ptrSize;

	//get buffLenght
	if (GetUserPreferredUILanguages(flags, &langs, nullptr  ,&buffLenght )) {
	}
	else {std::cout <<"error gettin languages in buffer lenght\n";}

        std::basic_string<wchar_t> languagesBuffer (static_cast<int>(buffLenght),'\0');
	if (GetUserPreferredUILanguages(
				flags,
				&langs, 
				languagesBuffer.data(),
				&buffLenght )) {
	} //if
	else {std::cout <<"error getting language lists\n";}
        // lista (string) de limbi este separata prin \0 caracter
        return std::wstring (languagesBuffer.c_str());

}
#elif OS_LINUX
std::string getLanguage(){
    // const char* const localname = std::getenv("LANG");
    std::string localname = std::getenv("LANG");
    std::setlocale (LC_ALL,localname);
    std::locale::global (std::locale(localname));
    std::cout << localname <<std::endl;
    return std::string();
}

#endif //OS




