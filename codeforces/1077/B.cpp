/**
 🍪 the_hyp0cr1t3
 🍪 01.11.2020 00:57:40
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
    int i, n, ans = 0;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i+3 <= n; i++)
        if(a[i] == 1 and a[i+1] == 0 and a[i+2] == 1)
            ans++, i += 2;
    cout << ans << '\n';
}