/**
 🍪 the_hyp0cr1t3
 🍪 11.10.2020 15:40:46
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
const int M = 26;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n; string s, t; int64_t ans = 0;
    cin >> n >> s;
    t = s; reverse(all(t));

    array<queue<int>, M> holes;
    for(i = 0; i < n; i++)
        holes[t[i]-'a'].push(i);

    vector<int> a(n), seg(2*n);
    for(i = 0; i < n; i++) {
        a[i] = holes[s[i]-'a'].front();
        holes[s[i]-'a'].pop();
    }

    auto query = [&](int l, int r) {
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) res += seg[l++];
            if(r&1) res += seg[--r];
        } return res;
    };

    auto update = [&](int pos) {
        for(seg[pos += n] = 1; pos >>= 1;)
            seg[pos] = seg[pos<<1] + seg[pos<<1|1];
    };

    for(auto x: a) {
        ans += query(x, n);
        update(x);
    } cout << ans << '\n';
}