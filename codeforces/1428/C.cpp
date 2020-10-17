/**
 🍪 the_hyp0cr1t3
 🍪 17.10.2020 18:54:38
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
    int i, n, ans = 0; string s;
    cin >> s; n = sz(s);
    int cntb = 0;
    reverse(all(s));
    for(auto c: s) {
        if(c == 'A') {
            if(cntb) ans += 2, cntb--;
        } else {
            cntb++;
        }
    } 
    ans += cntb/2*2;
    ans = n - ans;
    cout << ans << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}