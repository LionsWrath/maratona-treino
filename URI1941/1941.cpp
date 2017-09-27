#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <iomanip>

#define MAXSIZE 2010

using namespace std;

typedef pair<int, int> ii;

vector<bool> specialPositions;
string word;

int p[MAXSIZE][MAXSIZE];
int d[MAXSIZE][MAXSIZE];

int verifySpecial(int l, int r) {
    int special = 0;

    if (specialPositions[l]) special++;
    if (specialPositions[r]) special++;
    
    return special;
}

ii len(int l, int r) {
    int s = 0;

    if (p[l][r] != -1) {
        return ii(p[l][r], d[l][r]);
    }

    //Base
    if (l == r) {
        s = specialPositions[l];

        p[l][r] = s;
        d[l][r] = 1;

        //cout << s << ": " << l << " " << r << endl;
    
        return ii(s,1);
    }

    if (l+1 == r) {
        s = verifySpecial(l,r);
 
        p[l][r] = s;
        if(word[l] == word[r]) d[l][r] = 2;
        else d[l][r] = 1;
       
        //cout << s << ": " << l << " " << r << endl;
        
        if (word[l] == word[r]) return ii(s,2);
        else return ii(s,1);
    }

    //Recurrence
    if (word[l] == word[r]) {
        ii call = len(l + 1, r - 1); 

        s = verifySpecial(l,r);

        p[l][r] = s + call.first;
        d[l][r] = 2 + call.second;

        //cout << s + call.first << ": " << l << " " << r << endl;

        return ii(s + call.first, 2 + call.second);
    } else {
        ii call1 = len(l, r - 1);
        call1 = ii(call1.first + s, call1.second);
        
        ii call2 = len(l + 1, r);
        call2 = ii(call2.first + s, call2.second);

        s = verifySpecial(l,r);

        //cout << call1.first << ": " << l << " " << r << endl;       
        //cout << call2.first << ": " << l << " " << r << endl;

        if (call1.first > call2.first) {
        
            p[l][r] = call1.first;
            d[l][r] = call1.second;
    
            return call1;
        }

        if (call2.first > call1.first) {
            
            p[l][r] = call2.first;
            d[l][r] = call2.second;

            return call2;
        }
        
        if (call1.second > call2.second) {
                
            p[l][r] = call1.first;
            d[l][r] = call1.second;

            return call1;
        } else { 

            p[l][r] = call2.first;
            d[l][r] = call2.second;

            return call2; 
        }
    }
}

int main() {
    int N, M;

    cin >> word;

    specialPositions.assign(word.size(), false);
    memset(p, -1, MAXSIZE*MAXSIZE*sizeof(int));
    memset(d, -1, MAXSIZE*MAXSIZE*sizeof(int));

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> M;

        specialPositions[M-1] = true;
    }

    ii call = len(0, word.size() - 1);

    cout << call.second << endl;
    //cout << call.first  << endl;

    return 0;
}

