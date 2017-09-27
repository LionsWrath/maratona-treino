#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int A, B, C, D;
    int m1, m2, m3;

    cin >> A >> B >> C >> D;

    m1 = abs((A + B) - (C + D));
    m2 = abs((A + C) - (B + D));
    m3 = abs((A + D) - (C + B));

    cout << min(m1, min(m2, m3)) << endl;

    return 0;
}
