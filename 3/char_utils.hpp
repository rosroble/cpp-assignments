#ifndef CHAR_UTILS_H
#define CHAR_UTILS_H

#include <cstdlib>

namespace cutils {
    char* clone_string(const char* str);
    int strlen(const char* str);
    char* strcpy(char* dest, const char* str);
    char* generateRandomCString(size_t length);
}

#endif