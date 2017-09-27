#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int A, B, C;

    cin >> A >> B >> C;
    if ( A == B || A == C || B == C) cout << "S" << endl;
    else if (A + B == C || A + C == B || B + C == A) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
}
