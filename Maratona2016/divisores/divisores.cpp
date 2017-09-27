#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll A, B, C, D;

    cin >> A >> B >> C >> D;

    if (C%A != 0 || A%B == 0) {
        cout << -1 << endl;
        return 0;
    } 

    for (int i=A; i<=C; i += A) {
        if (C%i == 0) {
            if (i%A == 0) {
                if (i%B != 0) {
                    if (D%i != 0) {
                        cout << i << endl;
                        return 0;
                    }
                }
            }
        } 
    }

    cout << -1 << endl;
    
    return 0;
}
