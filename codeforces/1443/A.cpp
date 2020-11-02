/**
 🍪 the_hyp0cr1t3
 🍪 02.11.2020 20:06:24
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 401;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i;
    array<int, N> spf; iota(all(spf), 0);
    vector<int> primes{2}; primes.reserve(N);
    for(int z = 4; z < N; z += 2) spf[z] = 2;
    for(int z = 3; z*z < N; z += 2)
        if(spf[z] == z) for(int y = z*z; y < N; y += z*2)
            if(spf[y] == y) spf[y] = z;
    for(int z = 3; z < N; z += 2) 
        if(spf[z] == z) primes.pb(z);
    
    int Q; cin >> Q;
    while(Q--) {
        int n; cin >> n;
        for(i = 0; i < n; i++)
            cout << 2*n + 2*i << " \n"[i == n-1];
    }
}