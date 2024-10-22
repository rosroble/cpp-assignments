#include "strint.hpp"
#include <iostream>

using namespace lab2;
using namespace std;

const static char* five = "five";

void pass_to_func(Strint s) {
    s.print_string();
}

void pass_to_func_ref(Strint &s) {
    s.print_string();
} 

Strint return_from_func() {
    return Strint{3, "three"};
}

Strint& return_from_func_ref() {
    static Strint s{2, "two"};
    return s;
}

int main() {

    cout << "creating static object" << endl;
    static Strint sstatic{5, five};
    cout << endl;

    cout << "creating non-static object" << endl;
    Strint classic;
    cout << endl;

    cout << "creating non-static object + init" << endl;
    Strint classic_init{1, "one"};
    cout << endl;

    cout << "init vector" << endl;
    Strint strints[3];
    cout << endl;

    cout << "passing to function" << endl;
    pass_to_func(classic_init);
    cout << endl;

    cout << "passing to function ref" << endl;
    pass_to_func_ref(classic_init);
    cout << endl;

    cout << "return from function" << endl;
    return_from_func().print_string();  
    cout << endl;

    cout << "return from function ref" << endl;
    return_from_func_ref().print_string();  
    cout << endl;
}
