#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <iomanip>

#define MAXSIZE 2600

using namespace std;

typedef pair<int, int> ii;

vector<bool> sp;
string word;

ii      dp[MAXSIZE][MAXSIZE];
bool    seen[MAXSIZE][MAXSIZE];

ii len(int l, int r) {
    //Base
    if (r < l) return ii(0,0);
    if (l == r) {
        ii ret(sp[l], 1);

        dp[l][r] = ret;

        return ret;
    }
    
    if (seen[l][r]) return dp[l][r];

    seen[l][r] = true;

    //Recurrence

    ii call = len(l + 1, r - 1); 
    if (word[l] == word[r]) {
        call.first += sp[l] + sp[r];
        call.second += 2;

        dp[l][r] = call;
    } 
    
    dp[l][r] = max(dp[l][r], len(l, r - 1));
    dp[l][r] = max(dp[l][r], len(l + 1, r));

    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;

    cin >> word;

    sp.assign(word.size(), false);
    memset(seen, 0, MAXSIZE*MAXSIZE*sizeof(bool));

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> M;

        sp[M-1] = true;
    }

    cout << len(0, word.size() - 1).second << endl;

    return 0;
}
