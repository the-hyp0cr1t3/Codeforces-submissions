/**
 🍪 the_hyp0cr1t3
 🍪 11.10.2020 14:51:03
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
    int i, n;
    cin >> n;
    multiset<int> odds, evens;
    for(i = 1; i <= n; i++) {
        if(i&1) odds.insert(i);
        else evens.insert(i);
    }

    auto get = [&](auto& s) {
        int x = *s.rbegin();
        s.erase(s.find(x));
        return x;
    };

    vector<pair<int, int>> ans;
    while(true) {
        if(sz(odds) <= 1 and sz(evens) <= 1)
            break;
        if(sz(odds) >= 2 and sz(evens) >= 2) {
            if(*odds.rbegin() > *evens.rbegin()) {
                int x = get(odds);
                int y = get(odds);
                ans.pb(x, y);
                x = x + y + 1 >> 1;
                if(x&1) odds.insert(x);
                else evens.insert(x);
            } else {
                int x = get(evens);
                int y = get(evens);
                ans.pb(x, y);
                x = x + y + 1 >> 1;
                if(x&1) odds.insert(x);
                else evens.insert(x);
            }
        }
        else if(sz(odds) >= 2) {
            int x = get(odds);
            int y = get(odds);
            ans.pb(x, y);
            x = x + y + 1 >> 1;
            if(x&1) odds.insert(x);
            else evens.insert(x);
        }
        else if(sz(evens) >= 2) {
            int x = get(evens);
            int y = get(evens);
            ans.pb(x, y);
            x = x + y + 1 >> 1;
            if(x&1) odds.insert(x);
            else evens.insert(x);
        }
    }

    if(sz(odds) and sz(evens)) {
        int x = get(odds);
        int y = get(evens);
        ans.pb(x, y);
        x = x + y + 1 >> 1;
        if(x&1) odds.insert(x);
        else evens.insert(x);
    }

    if(sz(odds)) cout << get(odds) << '\n';
    else cout << get(evens) << '\n';

    assert(sz(ans) == n-1);
    for(auto [u, v]: ans) cout << u << ' ' << v << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}   