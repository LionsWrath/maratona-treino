#include <bits/stdc++.h>
#define endl '\n'

#define INF 9999999

using namespace std;

vector<int> sizes;
unordered_map<int, int> memoi;

int process(int rest) {
    if (0 == rest) return 0;
    if (memoi.find(rest) != memoi.end()) 
        return memoi[rest];

    int times = INF;
    for (int i=0; i<sizes.size(); i++) {
        if (sizes[i] <= rest) {
            times = min(process(rest - sizes[i]), times);
        }
    }

    memoi[rest] = times + 1;
    
    return memoi[rest];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T, N, M;

    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N >> M;

        int aux;
        for (int j=0; j<N; j++) {
            cin >> aux;
            sizes.push_back(aux);
        }

        sort(sizes.begin(), sizes.end(), std::greater<int>());

        cout << process(M) << endl;

        sizes.clear();
        memoi.clear();
    }
    

    return 0;
}
