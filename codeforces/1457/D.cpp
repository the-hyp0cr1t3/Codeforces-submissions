/**
 🍪 the_hyp0cr1t3
 🍪 29.11.2020 21:08:51
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
const int M = 30;
int64_t a[N], pref[N], suf[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, l, r, n, ans = INF;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i <= n; i++)
        pref[i] = pref[i-1] ^ a[i];
    for(i = n; i; i--)
        suf[i] = suf[i+1] ^ a[i];

    auto get = [&](int l, int r) {
        return pref[n] ^ pref[l-1] ^ suf[r+1];
    };

    for(i = 1; i+1 <= n; i++)
        for(l = 1; l <= M and i-l+1; l++)
            for(r = 1; r <= M and i+r <= n; r++)
                if(get(i-l+1, i) > get(i+1, i+r))
                    ans = min(ans, l + r - 2);

    cout << (ans == INF? -1 : ans);

} // ~W