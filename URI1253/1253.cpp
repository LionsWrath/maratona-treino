#include <iostream>
#include <string>
#include <map>

using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

map<char, int> charToInt = {   {'A',  0}, {'B',  1}, {'C',  2}, {'D',  3}, 
                               {'E',  4}, {'F',  5}, {'G',  6}, {'H',  7}, 
                               {'I',  8}, {'J',  9}, {'K', 10}, {'L', 11}, 
                               {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15},
                               {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, 
                               {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, 
                               {'Y', 24}, {'Z', 25}};

int main() {
    int N;
    int M;
    string letter;

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> letter >> M;

        for (int j=0; j<letter.size(); j++) {
            int index = (charToInt[letter[j]] - M);

            if (index < 0) index += 26;
            else index %= 26;

            letter[j] = alphabet[index];
        }

        cout << letter << endl;
    }
    
    return 0;
}
