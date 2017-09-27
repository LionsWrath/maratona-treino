#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef unsigned long long ull;
typedef long long int ll;

ull _sieve_size;
bitset<1000010> bs;
vector<int> primes;

void sieve(ull upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;

    for (ull i = 2; i <= _sieve_size; i++)
        if (bs[i]) {
            for (ull j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int) i);
        }
}

ull primeFactors(ull N, ull SQRTN) {
    vector<int> factors;

    ull PF_idx = 0;
    ull PF = primes[PF_idx];

    while (PF <= SQRTN) {
        while (N % PF == 0) {
            N /= PF;
            factors.push_back(PF);
        }
        PF = primes[++PF_idx];
    }

    if (N != 1) factors.push_back(N);

    return set<int>(factors.begin(), factors.end()).size();
}

ull nCR(ull n) {
    vector<ull> row(n+1, 0);
    row[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = i; j > 0; j--) {
             row[j] += row[j - 1];
        }
    }

    return accumulate(row.begin(), row.end() - 2, 0); //The last two are not needed in this case
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ull N, F;
    vector<ull> factors;

    cin >> N;

    ull SQRTN = sqrt(N);

    sieve(SQRTN + 24);

    F = primeFactors(N, SQRTN);

    if (F <= 1) cout << "0" << endl;
    else cout << nCR(F) << endl;;
    
    return 0;
}
