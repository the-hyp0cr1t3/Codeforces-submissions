/**
 🍪 the_hyp0cr1t3
 🍪 10.10.2020 20:20:46
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
    int i, n, cnt0 = 0, sumneg = 0, sumpos = 0;
    cin >> n;
    vector<int> pos, neg;
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 0) cnt0++;
        else if(x < 0) neg.pb(x), sumneg += -x;
        else pos.pb(x), sumpos += x;
    }
    if(sumneg == sumpos) return cout << "NO" << '\n', 0;
    if(sumneg > sumpos) swap(neg, pos);
    cout << "YES" << '\n';
    for(auto x : pos) cout << x << ' ';
    for(auto x : neg) cout << x << ' ';
    while(cnt0--) cout << 0 << ' ';
    cout << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}