#include "strint.hpp"
#include <iostream>
#include <vector>

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

vector<Strint> vector_init() {
    return vector<Strint> (5);
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

    cout << "move constructor: std::move" << endl;
    Strint x{22, "twenty-two"};
    Strint y = std::move(x);
    x.print_string(); // should print nothing
    y.print_string(); // should print twenty-two
    cout << endl;

    cout << "move constructor: temp value assignment" << endl;
    Strint z = return_from_func(); // could be moved, but not guaranteed (RVO)
    cout << endl;

    cout << "move assignment" << endl;
    y = std::move(z); // should call move assignment operator
    cout << endl;

    cout << "vector init" << endl;
    vector_init();
    cout << endl;
    
}
