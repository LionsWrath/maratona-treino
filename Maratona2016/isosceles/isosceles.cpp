#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<int> wood, lef, rig;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N, A;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A;
        wood.push_back(A);
    }

    int back = 0, front = 0;
    for (int i=0; i<N; i++) {
        if (wood[i] > back) back++;
        else back = wood[i]; 

        if (wood[N-1-i] > front) front++;
        else front = wood[N-1-i]; 

        rig.push_back(front); lef.push_back(back);
    }

    int maxValue = 0;
    for (int i=0; i<N; i++) {
        maxValue = max( min(lef[i], rig[N-1-i]), maxValue);
    }

    cout << maxValue << endl;

    return 0;
}
