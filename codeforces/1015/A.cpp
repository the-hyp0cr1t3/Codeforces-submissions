/**
 🍪 the_hyp0cr1t3
 🍪 16.11.2020 18:14:47
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
int f[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m;
    cin >> n >> m;
    for(i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        while(l <= r) f[l++] = 1;
    }
    int ans = 0;
    for(i = 1; i <= m; i++)
        ans += !f[i];

    cout << ans << '\n';
    for(i = 1; i <= m; i++)
        if(!f[i]) cout << i << ' ';
} // ~W