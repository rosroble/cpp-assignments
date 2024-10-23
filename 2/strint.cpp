#include "strint.hpp"
#include "char_utils.hpp"
#include <iostream>

using namespace lab2;
using namespace std;

Strint::Strint() {
    cout << "empty constructor called" << endl;
    this->num = 0;
    this->str = nullptr;
    this->str_len = 0;
}

Strint::Strint(int num, const char *str) {
    cout << "parameterized constructor called" << endl;
    this->num = num;
    this->str = cutils::clone_string(str);
    this->str_len = cutils::strlen(str);
}

// copy
Strint::Strint(const Strint &s) {
    cout << "copy constructor called" << endl;
    if (this == &s) {
        return;
    }
    this->num = s.num;
    this->str_len = s.str_len;
    this->str = cutils::clone_string(s.str);
}

// move
Strint::Strint(Strint &&s) {
    cout << "move constructor called" << endl;
    *this = std::move(s);
}

// destroy
Strint::~Strint() {
    cout << "destructor called" << endl;
    delete[] this->str;
}

// assignment
Strint& Strint::operator=(const Strint &&other) {
    cout << "assignment operator called" << endl;
    if (this == &other) {
        return *this;
    }
    if (this->str_len != other.str_len) {
        delete[] this->str;
        this->str = new char[other.str_len];
        this->str_len = other.str_len;
    }

    strcpy(this->str, other.str);
    return *this;
}

// assignment with move
Strint& Strint::operator=(Strint &&other) noexcept {
    cout << "assignment with move operator called" << endl;
    if (this == &other) {
        return *this;
    }

    delete[] this->str;

    this->num = other.num;
    this->str = other.str;
    this->str_len = other.str_len;

    other.str = nullptr;
    other.str_len = 0;
    other.num = -1;

    return *this;
}

void Strint::print_string() {
    if (this->str != nullptr) {
        cout << this->str << endl;
    }
}

int Strint::get_int() {
    return this->num;
}