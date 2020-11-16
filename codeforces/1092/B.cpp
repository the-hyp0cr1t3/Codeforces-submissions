/**
 🍪 the_hyp0cr1t3
 🍪 16.11.2020 12:10:00
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
    int i, n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    sort(all(a));

    for(i = 1; i < n; i+=2)
        ans += a[i] - a[i-1];

    cout << ans << '\n';
} // ~W