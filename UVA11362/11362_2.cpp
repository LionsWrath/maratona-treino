#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX_N 100010

vector<string> stringlist;

string T, P;

int main() {
    int N;
    int M;

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> M;

        for (int j=0; j<M; j++) {
            string I;
            cin >> T;
        
            stringlist.push_back(T);
        }

        bool consistent = true;

        for (int j=0; j<stringlist.size(); j++) {
            T = stringlist[j];
            
            for (int k=0; k<stringlist.size(); k++) {
                if (T.size() >= stringlist[k].size() && k != j) {
                    P = stringlist[k];
                    
                    int i = 0;
                    while (T[i] == P[i]) i++;

                    if (i == P.size()) consistent = false;
                }
            }
        }
        
        if (consistent) cout << "YES" << endl;
        else cout << "NO" << endl;

        stringlist.clear();
    }

    return 0;
}
