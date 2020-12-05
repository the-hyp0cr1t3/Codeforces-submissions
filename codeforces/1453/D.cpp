/**
 🍪 the_hyp0cr1t3
 🍪 05.12.2020 20:09:22
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

const int64_t DESPACITO = 1e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int64_t> a{2};
    while(a.back() < DESPACITO)
        a.pb((1ll<<sz(a)+2)-2);
    int Q; cin >> Q;
    while(Q--) {
        string ans;
        int64_t x; cin >> x;
        if(x&1) { cout << -1 << '\n'; continue; }
        for(int i = sz(a)-1; ~i; --i)
            while(x >= a[i])
                ans += '1' + string(i, '0'), x -= a[i];
        cout << sz(ans) << '\n';
        for(auto c: ans) cout << c << ' '; cout << '\n';
    }
} // ~W 