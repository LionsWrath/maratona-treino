#include <bits/stdc++.h>

using namespace std;

int matrix[1001][1001];
int M, N;

int search(int i, int j) {
    int value = 0;
    
    for (int m=i; m<i+M; m++) {
        for (int n=j; n<j+N; n++) {
            value += matrix[m][n]; 
            //cout << i << " " << j << ":" << aux << endl;
         }
    }

    return value;
}

int main() {
    int L, C;
    int max = 0;

    cin >> L >> C >> M >> N;

    for (int i=0; i<L; i++) {
        for (int j=0; j<C; j++) {
           cin >> matrix[i][j];
        }
    }

    for (int i=0; i<L-M+1; i++) {
        for (int j=0; j<C-N+1; j++) {
           int aux = search(i, j);

           if (aux > max) max = aux;
        }
    }

    cout << max << endl;

    return 0;
}
