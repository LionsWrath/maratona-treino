#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int N, K, AUX;
    vector<int> values;

    cin >> N >> K;

    for (int i=0; i<N; i++) {
        cin >> AUX;

        values.push_back(AUX);
    }

    sort(values.begin(), values.end(), greater<int>());

    int last = values[K-1], winners = K;
    for (int i=K; i<N; i++) {
        if (last == values[i]) winners++;
        else break;
    }

    cout << winners << endl;

    return 0;
}
