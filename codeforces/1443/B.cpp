/**
 🍪 the_hyp0cr1t3
 🍪 02.11.2020 20:18:37
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

int the_real_main() {
    int i, j, k, n, a, b, ans = 0; string s;
    cin >> a >> b >> s;
    n = sz(s);
    while(sz(s) and s.back() == '0') s.pop_back();
    reverse(all(s));
    while(sz(s) and s.back() == '0') s.pop_back();
    n = sz(s);
    for(i = j = 0; i < n; i=j) {
        while(j < n and s[j] == s[i]) j++;
        if(s[i] == '1') ans += a;
        else if(b * (j-i) <= a) ans += b * (j-i) - a;
    } cout << ans << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}