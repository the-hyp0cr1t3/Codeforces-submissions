/**
 🍪 the_hyp0cr1t3
 🍪 31.10.2020 20:58:45
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
const int INF = 2e9, MOD = 998244353;
const int N = 2e5 + 5;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i; array<int64_t, 3> a;
    for(i = 0; i < 3; i++) {
        cin >> a[i];
        a[i] = a[i] * (a[i]+1) / 2 % MOD;
    } cout << a[0] * a[1] % MOD * a[2] % MOD;
}