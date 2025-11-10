#include <iostream>
#include <vector>

#ifdef _MSC_VER
#include <windows.h>
const bool &x = SetConsoleOutputCP(65001);
#endif

//#include <clocale>
//#include <locale>
//#include <cstdlib>
//#include <winnls.h>

#include "getLanguage.h"
void get_language(){
	std::cout << "getting language \n";
	DWORD flags = MUI_LANGUAGE_NAME,buffLenght = 0;
	ULONG langs = 0 ;
	PZZWSTR ptrLang;
	PULONG ptrSize;
	if (GetUserPreferredUILanguages(flags, &langs, nullptr  ,&buffLenght )) {
		std::cout <<"lang in if: " << langs<< std::endl;
		std::cout <<"buff lenght: " << buffLenght << std::endl;
	}
	else {std::cout <<"error in 1\n";}

	// ar trebuii sa functioneaze cu **char (sau **wchar) ? cum new (size of buffer) ?
	std::vector<wchar_t> languagesBuffer  (static_cast<int>(langs));
	if (GetUserPreferredUILanguages(
				flags,
				&langs, 
				languagesBuffer.data(),
				&buffLenght )) {
		std::cout <<std::endl;
		std::cout <<"lang in if: " << langs<< std::endl;
		std::cout <<"buff lenght: " << buffLenght << std::endl;
		std::cout << "Language:\n";

		// lista (vector) de limbi este separata prin \0 caracter
		for (int  i =0; i< buffLenght ; i++ ) {
			if (languagesBuffer[i] == '\0')
				languagesBuffer[i]=' ';
			std::wcout << languagesBuffer[i] ;
		}
		std::cout <<std::endl;
	}
	else {std::cout <<"error im 2\n";}

	std::cout <<"lang: " << langs << std::endl;
	std::cout << "\n\ntest\n";
}



