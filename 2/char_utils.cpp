#include "char_utils.hpp"

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