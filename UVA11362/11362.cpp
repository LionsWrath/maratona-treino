#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

#define MAX_N 100010

vector<string> stringlist;

char I[15];
string T, P;
int n, m;

bool search() {
    int i = 0, j = 0;

    while (j != m) {
        if (T[i] != P[j]) return true;
        
        i++; 
        j++;
    }
    return false;
}

int main() {
    int N;
    int M;

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> M;

        for (int j=0; j<M; j++) {
            scanf("%s", I);
        
            stringlist.push_back(I);
        }

        bool consistent = true;
        for (int j=0; j<stringlist.size(); j++) {
            T = stringlist[j];
            n = T.size();

            for (int k=0; k<stringlist.size(); k++) {
                if (stringlist[k].size() < n) {
                    P = stringlist[k];
                    m = P.size();

                    if (!search()) { 
                        consistent = false; 
                    }
                }
            }
        }

        if (consistent) cout << "YES" << endl;
        else cout << "NO" << endl;

        stringlist.clear();
    }

    return 0;
}
