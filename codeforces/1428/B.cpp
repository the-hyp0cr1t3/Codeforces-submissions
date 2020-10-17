/**
 🍪 the_hyp0cr1t3
 🍪 17.10.2020 18:42:29
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
    cin >> n >> s;
    int cnt[3] = {};
    for(auto c: s) {
        if(c == '>') cnt[0]++;
        else if(c == '<') cnt[1]++;
        else cnt[2]++;
    }
    if(cnt[0] == 0 or cnt[1] == 0) return cout << n << '\n', 0;
    s = s + s;
    cnt[2] *= 2;
    for(i = 0; i < n; i++) {
        if(s[i] == '-' and s[i+1] == '-') cnt[2]--;
    }
    cout << cnt[2] << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}