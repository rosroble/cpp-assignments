#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void gen(vector<string> &types, vector<string> &opers, ofstream &fout) {
    fout << "#include <iostream>" << endl;
	fout << "void f(void) {"<< endl;
    for (int i = 0; i < types.size(); i++) {
        fout << "\t" << types[i] << " " << types[i] << "_" << i << " = " << i + 1 << ";" << endl;
    }
    for (int i = 0; i < opers.size(); i++) {
        fout << "\t" << "std::cout << ";
        for (int j = 0; j < types.size() - 1; j++) {
            fout << types[j] << "_" << j << " " << opers[i] << " ";
        }
        fout << types[types.size() - 1] << "_" << types.size() - 1 << " << std::endl" << ";" << endl;
    }
    fout << "}" << endl;

    // entrypoint
    fout << "int main() { f(); return 0; }" << endl;
}

int main() {
    int n;
    cout << "Enter the number of types: ";
    cin >> n;
    if (n <= 0) {
        cout << "Bad args: n must be > 0";
        return -1;
    }

    vector<string> types;
    for (int i = 0; i < n; i++) {
        string type;
        cin >> type;
        types.push_back(type);
    }

    cout << "Enter the number of operations: ";
    cin >> n;
    if (n <= 0) {
        cout << "Bad args: n must be > 0";
        return -1;
    }
    vector<string> opers;
    for (int i = 0; i < n; i++) {
        string oper;
        cin >> oper;
        opers.push_back(oper);
    }

	ofstream fout("func.cpp");

    gen(types, opers, fout);
	
	fout.close();
    return 0;
}