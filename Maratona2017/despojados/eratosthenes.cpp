#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef unsigned long long ull;

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

bool isPrime(ull N) {
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < (int) primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    sieve(1000000);

    cout << "[";
    for (int i = 0; i < primes.size() - 2; i++)
        cout << primes[i] << ", ";
    cout << primes[primes.size()-1] << "]";

    return 0;
}
