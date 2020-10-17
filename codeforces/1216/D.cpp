/**
 🍪 the_hyp0cr1t3
 🍪 17.10.2020 14:16:43
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
int a[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, mx, g = 0; int64_t ans = 0;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];
    mx = *max_element(a, a+n);
    for(i = 0; i < n; i++)
        g = __gcd(g, mx-a[i]);
    for(i = 0; i < n; i++)
        ans += (mx-a[i])/g;
    cout << ans << ' ' << g << '\n';
}