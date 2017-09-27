#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string N;
    string b_name, o_name;

    getline(cin, o_name);
    b_name = o_name;
    transform(b_name.begin(), b_name.end(), b_name.begin(), ::tolower); 

    while(getline(cin, N)) {
        string aux = N;
        transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
        if (b_name.compare(aux) < 0) {
            o_name = N;
            b_name = aux;
        }
    }

    cout << o_name << endl;
    
    return 0;
}
