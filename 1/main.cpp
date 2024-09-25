#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string space2underscore(std::string text)
{
    replace(text.begin(), text.end(), ' ', '_');
    return text;
}

void gen(vector<string> &types, vector<string> &opers, ofstream &fout) {
    fout << "#include <iostream>" << endl;
	fout << "void f(void) {"<< endl;
    for (int i = 0; i < types.size(); i++) {
        fout << "\t" << types[i] << " " << space2underscore(types[i]) << "_" << i << " = " << i + 1 << ";" << endl;
    }
    for (int i = 0; i < opers.size(); i++) {
        fout << "\t" << "std::cout << ";
        for (int j = 0; j < types.size() - 1; j++) {
            fout << space2underscore(types[j]) << "_" << j << " " << opers[i] << " ";
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
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "-----" << i << endl;
        string type;
        getline(cin, type);
        types.push_back(type);
    }

    cout << "Enter the number of operations: ";
    cin >> n;
    if (n <= 0) {
        cout << "Bad args: n must be > 0";
        return -1;
    }
    
    vector<string> opers;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string oper;
        getline(cin, oper, '\n');
        opers.push_back(oper);
    }

	ofstream fout("func.cpp");

    gen(types, opers, fout);
	
	fout.close();
    return 0;
}