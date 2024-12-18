#include "char_utils.hpp"
#include <cstdlib>
#include <ctime>

char* cutils::clone_string(const char* str) {
    if (!str) {
        return nullptr;
    }
    int len = cutils::strlen(str);
    if (len == 0) {
        return nullptr;
    }
    char* cloned_str = new char[len];
    return cutils::strcpy(cloned_str, str);
}

int cutils::strlen(const char* str) {
    const char* c = str;
    while (*c != '\0') {
        c++;
    }
    return c - str;
}

char* cutils::strcpy(char* dest, const char* str) {
    char* dest_start = dest;
    while (*str != '\0') {
        *dest++ = *str++;
    }
    *dest = *str;
    return dest_start;
}

char* cutils::generateRandomCString(size_t length) {
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const size_t characterSetSize = sizeof(characters) - 1;

    char* randomCString = new char[length + 1];

    for (size_t i = 0; i < length; ++i) {
        randomCString[i] = characters[std::rand() % characterSetSize];
    }

    randomCString[length] = '\0';

    return randomCString;
}