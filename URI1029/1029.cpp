#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef pair<int, int> ii;

map<int, ii> memoi;

pair<int, int> fib(int value) {
    if (0 == value) return ii(0, 1);
    if (1 == value) return ii(1, 1);

    if (memoi.find(value - 1) == memoi.end()) memoi[value - 1] = fib(value - 1);
    if (memoi.find(value - 2) == memoi.end()) memoi[value - 2] = fib(value - 2);

    ii l = memoi[value - 1];
    ii r = memoi[value - 2];

    return ii(l.first + r.first, l.second + r.second + 1);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N, X;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> X;
        ii result = fib(X);
        cout << "fib(" << X << ") = " << result.second - 1 << " calls = " << result.first << endl;
    }
    
    return 0;
}
