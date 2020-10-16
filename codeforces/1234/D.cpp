/**
 🍪 the_hyp0cr1t3
 🍪 16.10.2020 17:26:16
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
    int i, j, n, Q; string s;
    cin >> s >> Q; n = sz(s);
    
    array<vector<int>, M> seg;
    for(i = 0; i < M; i++)
        seg[i].resize(2*n);
    for(i = 0; i < n; i++)
        seg[s[i]-'a'][i+n]++;

    for(i = 0; i < M; i++)
        for(j = n-1; j; --j)
            seg[i][j] = seg[i][j<<1] + seg[i][j<<1|1];

    auto query = [&](int L, int R) {
        int res = 0; L += n; R += n;
        for(i = 0; i < M; i++) {
            int ok = 0, l = L, r = R;
            for(; l < r; l >>= 1, r >>= 1) {
                if(l&1) ok |= seg[i][l++];
                if(r&1) ok |= seg[i][--r];
            } res += !!ok;
        } return res;
    };

    auto update = [&](int z, int pos, int val) {
        for(seg[z][pos += n] += val; pos >>= 1;)
            seg[z][pos] = seg[z][pos<<1] + seg[z][pos<<1|1];
    };

    while(Q--) {
        int t; cin >> t;
        if(t == 1) {
            int pos; char c; cin >> pos >> c; --pos;
            update(s[pos]-'a', pos, -1);
            s[pos] = c;
            update(s[pos]-'a', pos, +1);
        } else {
            int l, r; cin >> l >> r;
            cout << query(--l, r) << '\n';
        }
    }
}