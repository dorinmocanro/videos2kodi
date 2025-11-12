#ifndef GET_LANGUAGE_H
#define GET_LANGUAGE_H
#include <string>
#include "platform.h" 
#ifdef OS_WIN
std::wstring getLanguage(); 
#elif OS_LINUX
std::string getLanguage();
#endif //OS selection
#endif
