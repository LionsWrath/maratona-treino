#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

map<char, int> charToInt = {   {'a',  0}, {'b',  1}, {'c',  2}, {'d',  3}, 
                               {'e',  4}, {'f',  5}, {'g',  6}, {'h',  7}, 
                               {'i',  8}, {'j',  9}, {'k', 10}, {'l', 11}, 
                               {'m', 12}, {'n', 13}, {'o', 14}, {'p', 15},
                               {'q', 16}, {'r', 17}, {'s', 18}, {'t', 19}, 
                               {'u', 20}, {'v', 21}, {'w', 22}, {'x', 23}, 
                               {'y', 24}, {'z', 25}
                           };

int main() {
    int N, M = 0;
    string line, aux;
    vector<bool> alphabet(26, false);

    getline(cin, line);
    stringstream ss(line);

    ss >> N;
    
    for (int i=0; i<N; i++) {
        getline(cin, line);
        
        for (int j=0; j<line.size(); j++) {
            if (line[j] != ' ' && line[j] != ',') {
                int index = charToInt[line[j]];
                
                if (alphabet[index] == false) {
                    alphabet[index] = true;
                    M++;
                }
            }
        }

        if      (M == 26) cout << "frase completa"          << endl;
        else if (M >= 13) cout << "frase quase completa"    << endl;
        else              cout << "frase mal elaborada"     << endl;

        M = 0;
        alphabet.assign(26, false);
    }

    return 0;
}
