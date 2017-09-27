#include <bits/stdc++.h>
#define endl '\n'

#define INF 9999999

using namespace std;

vector<int> ices;

int process(int M) {
    int dp[M];
    
    dp[0] = 0;

    for (int i=1; i<=M; i++) {
        dp[i] = INF;
        for (int j=0; j<ices.size(); j++) {
            if (i - ices[j] >= 0) {
                dp[i] = min(dp[i], dp[ i - ices[j] ] + 1);
            } 
        }
    }

    return dp[M];
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
            ices.push_back(aux);
        }

        sort(ices.begin(), ices.end());

        cout << process(M) << endl;

        ices.clear();
    }
    

    return 0;
}
