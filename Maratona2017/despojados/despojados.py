from random import randint
from functools import reduce
import operator as op

limitn = 0
primes = []
not_prime = []

def sieve(limit):
    global limitn
    global primes
    global not_prime

    limitn = limit+1
    not_prime = [False] * limitn
    primes = []

    for i in range(2, limitn):
        if not_prime[i]:
            continue

        for f in range(i*2, limitn, i):
            not_prime[f] = True

        primes.append(i)

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def isPrime(N):
    global limitn
    global primes
    global not_prime

    if N <= limitn:
        return not not_prime[N]
    
    for p in primes:
        if N % p == 0:
            return False
    return True

def modularPow(b, e, m):
    r = 1

    while e > 0:
        if e & 1:
            r = (r * b) % m
        e >>= 1
        b = (b * b) % m
    
    return r

def pollardRho(N):
    global limitn
    global not_prime

    if N % 2 == 0:
        return 2
    if isPrime(N):
        return N

    x = randint(1, N + 1)
    y = x
    a = randint(1, N + 1)
    g = 1

    while g == 1:
        x = (modularPow(x, 2, N) + a + N) % N
        y = (modularPow(y, 2, N) + a + N) % N
        y = (modularPow(y, 2, N) + a + N) % N

        g = gcd(abs(x - y), N)

        if g == N:
            return pollardRho(N)

    if not isPrime(g):
        return pollardRho(N)
    return g

def ncr(n, r):
    r = min(r, n-r)

    if r == 0: return 1
    
    numer = reduce(op.mul, range(n, n-r, -1))
    denom = reduce(op.mul, range(1, r+1))
    
    return numer//denom #integer division

def main():

    N = int(input())
    sieve(1000010)

    factors = []

    while N > 1:
        factors.append(pollardRho(N))
        N = int(N / factors[-1])

    value = len(set(factors))

    if value <= 1:
        print("0")
    else:
        combinations = 0
        for v in range(2, value+1):
            combinations += ncr(value, v)
        print(combinations)

if __name__ == "__main__": main()
