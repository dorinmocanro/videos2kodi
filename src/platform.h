#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define OS_WIN 1

#elif __APPLE__
#define OS_APPLE 1

#elif defined (LINUX) || defined (__LINUX__) || defined (__linux__)
#define OS_LINUX 1
#endif
