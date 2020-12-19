/**
 🍪 the_hyp0cr1t3
 🍪 19.12.2020 15:10:24
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
    int i, n, m;
    cin >> n >> m;
    vector<int64_t> a(n), b(m);
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;

    sort(all(a));
    int64_t g = 0;
    for(i = 1; i < n; i++)
        g = __gcd(g, a[i]-a[i-1]);

    for(i = 0; i < m; i++)
        cout << __gcd(g, a[0] + b[i]) << " \n"[i == m-1];
} // ~W 