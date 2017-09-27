#include <bits/stdc++.h>
#define endl '\n'

#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define BOTH  3

using namespace std;

typedef long long int ll;

int tab[501][501];

ll partB = 0, partW = 0;

void printTab(int N) {
    cout << endl;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int verify(int A, int B) {
    if (A == BOTH || B == BOTH) return BOTH;
    if (A == WHITE) { 
        if (B == BLACK) return BOTH ;
        if (B == WHITE) return WHITE;
        if (B == EMPTY) return WHITE;
    }
    if (A == BLACK) {
        if (B == BLACK) return BLACK;
        if (B == WHITE) return BOTH ;
        if (B == EMPTY) return BLACK;
    }
    if (A == EMPTY) {
        if (B == WHITE) return WHITE;
        if (B == BLACK) return BLACK;
    }

    return EMPTY;
}

int count(int i, int j, int k) { 
    int qtdSpaces = verify(verify(tab[i][j], tab[i+1][j]),verify(tab[i][j+1], tab[i+1][j+1]));

    if (BLACK == qtdSpaces) partB++; 
    if (WHITE == qtdSpaces) partW++;
    
    return qtdSpaces;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N, P, L, C;

    cin >> N >> P;
    
    for (int i=0; i<P; i++){
        cin >> L >> C;
        tab[L - 1][C - 1] = BLACK;
    }

    for (int i=0; i<P; i++) {
        cin >> L >> C;
        tab[L - 1][C - 1] = WHITE;
    }

    for (int k=2; k<N; k++) {
        for (int i=0; i<N-k+1; i++) {
            for (int j=0; j<N-k+1; j++) {
                tab[i][j] = count(i, j, k); 
            }
        }
    }

    cout << partB + P << " " << partW + P << endl;
    return 0;
}
