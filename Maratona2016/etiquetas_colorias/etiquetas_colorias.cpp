#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int R, G, B;
    
    cin >> hex >> R >> G >> B;

    ll qtdG = pow(floor(R/G), 2);
    ll qtdB = pow(floor(G/B), 2);

    ll total = qtdG + qtdG*qtdB;

    cout << hex << total + 1 << endl;

    return 0;
}
