#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef pair<int, int> ii;

map<int, ii> canhoto;
map<int, ii> destro;

map<int, int> visitedCanhoto;
map<int, int> visitedDestro;

int centerCanhoto(int idx) {
    if (0 == idx) return 0;

    visitedCanhoto[idx] = 0;
    return centerCanhoto(canhoto[idx].second) + 1;
}

int centerDestro(int idx) {
    if (0 == idx) return 0;

    visitedDestro[idx] = 0;
    return centerDestro(destro[idx].second) + 1;
}

int countCanhoto(int idx, int value) { 
    if (0 == idx) return value;

    int f = countCanhoto(canhoto[idx].first, 0);
    int s = countCanhoto(canhoto[idx].second, value + 1); 

    return max(f, s);
}

int countDestro(int idx, int value) {
    if (0 == idx) return value;

    int f = countDestro(destro[idx].first, 0);
    int s = countDestro(destro[idx].second, value + 1); 

    return max(f, s);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N, I, L, K;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> I >> L >> K;
        canhoto[I] = ii(L, K);
        visitedCanhoto[I] = 1;
    }
    
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> I >> L >> K;
        destro[I] = ii(K, L);
        visitedDestro[I] = 1;
    }

    int cc = centerCanhoto(1);
    int cd = centerDestro(1);
    int c = countCanhoto(1, 0); 
    int d = countDestro(1, 0);

    //Para conseguir o melhor valor, temos que pegar a comparação de árvore raiz - corpo entre a destra e canhota e pegar a maior delas 
    c = max(cc, c);
    d = max(cd, d);
    cout << canhoto.size() + destro.size() - max(min(cc, d), min(cd, c)) << endl;

    return 0;
}
