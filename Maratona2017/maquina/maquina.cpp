#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int A1, A2, A3;

    cin >> A1 >> A2 >> A3;

    int level1 = A2*2   +   A3*4;
    int level2 = A1*2   +   A3*2;
    int level3 = A1*4   +   A2*2;

    cout << min(level1, min(level2, level3)) << endl;

    return 0;
}
