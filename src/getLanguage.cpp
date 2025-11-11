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
	DWORD flags = MUI_LANGUAGE_NAME,buffLenght = 0;
	ULONG langs = 0 ;
	PZZWSTR ptrLang;
	PULONG ptrSize;

	//get buffLenght
	if (GetUserPreferredUILanguages(flags, &langs, nullptr  ,&buffLenght )) {
	}
	else {std::cout <<"error gettin languages in buffer lenght\n";}

	/* //testing
	ptrLang = new  std::remove_reference<decltype (*ptrLang)>::type();
	delete ptrLang;
	*/ //end testing

	// initiate pointer. may use uniqptr?

	std::vector<wchar_t> languagesBuffer  (static_cast<int>(buffLenght));
	if (GetUserPreferredUILanguages(
				flags,
				&langs, 
				languagesBuffer.data(),
				&buffLenght )) {
		// lista (vector) de limbi este separata prin \0 caracter
		for (int  i =0; i< buffLenght ; i++ ) {
			if (languagesBuffer[i] == '\0')
				languagesBuffer[i]=' ';
			std::wcout << languagesBuffer[i] ;
		} //for
		std::cout <<std::endl;
	} //if
	else {std::cout <<"error getting language lists\n";}
}



