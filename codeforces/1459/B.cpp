/**
 🍪 the_hyp0cr1t3
 🍪 19.12.2020 18:49:20
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
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    cout << ((n+1+(n&1)+1>>1) * (n+1-(n&1)+1>>1) << (n&1));
} // ~W 