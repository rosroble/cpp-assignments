#include "strint.hpp"
#include "char_utils.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace lab3;
using namespace std;

Strint::Strint() {
    // cout << "empty constructor called" << endl;
    this->num = 0;
    this->str = nullptr;
    this->str_len = 0;
}

Strint::Strint(int num, const char *str) {
    // cout << "parameterized constructor called" << endl;
    this->num = num;
    this->str = cutils::clone_string(str);
    this->str_len = cutils::strlen(str);
}

// copy
Strint::Strint(const Strint &s) {
    // cout << "copy constructor called" << endl;
    if (this == &s) {
        return;
    }
    this->num = s.num;
    this->str_len = s.str_len;
    this->str = cutils::clone_string(s.str);
}

// move
Strint::Strint(Strint &&s): num(s.num), str(s.str), str_len(s.str_len) {
    // cout << "move constructor called" << endl;
    s.str = nullptr; // Leave the moved-from object in a valid state
    s.str_len = 0;
}

// destroy
Strint::~Strint() {
    // cout << "destructor called" << endl;
    delete[] this->str;
}

// assignment
Strint& Strint::operator=(const Strint &other) {
    // cout << "assignment operator called" << endl;
    if (this == &other) {
        return *this;
    }
    if (this->str_len != other.str_len) {
        if (this->str) {
            delete[] this->str;
        }
        this->str = new char[other.str_len];
        this->str_len = other.str_len;
    }

    this->num = other.num;
    strcpy(this->str, other.str);
    return *this;
}

// assignment with move
Strint& Strint::operator=(Strint &&other) noexcept {
    // cout << "assignment with move operator called" << endl;
    if (this == &other) {
        return *this;
    }

    if (this->str != nullptr) {
        delete[] this->str;
    }

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

const int Strint::get_int() const {
    return this->num;
}

const char* Strint::get_str() const {
    return cutils::clone_string(this->str);
}

Strint Strint::get_random_strint() {
    char* random_str = cutils::generateRandomCString(10);
    int random_int = std::rand() % 10000;
    return Strint(random_int, random_str);
}

ostream& lab3::operator<<(ostream& os, const Strint& s) {
    os << "String: " << s.str << ", Num: " << s.num << endl;
    return os;
}