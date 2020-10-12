/**
 🍪 the_hyp0cr1t3
 🍪 12.10.2020 17:58:30
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

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
const int LG = 20;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m, Q;
    cin >> n >> m >> Q;
    vector<int> a(m), hsh(n+1);
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        hsh[x] = i;
    }

    for(i = 0; i < m; i++) {
        int x; cin >> x;
        a[i] = hsh[x];
    }

    vector<vector<int>> g(m + 1), anc(LG, vector<int>(m+1, -1));
    vector<int> cur(n, m), d(m+1), seg(2*m);
    for(i = m-1; ~i; i--) {
        g[cur[(a[i]+1)%n]].pb(i);
        cur[a[i]] = i;
    }
    
    auto dfs = Y([&](auto self, int v, int p) -> void {
        anc[0][v] = p;
        for(int k = 1; k < LG; k++) 
            anc[k][v] = ~anc[k-1][v]? anc[k-1][anc[k-1][v]] : -1;
        for(auto& x: g[v]) {
            if(x == p) continue;
            d[x] = d[v]+1;
            self(x, v);
        }
    });
    for(auto& x: g[m]) dfs(x, -1);

    auto walk = [&](int u, int d) {
        for(int z = 0; z < LG and ~u; z++) 
            if(d>>z & 1) u = anc[z][u];
        return ~u? u : m;
    };

    for(i = 0; i < m; i++)
        seg[i+m] = walk(i, n-1);

    for(i = m-1; i; i--)
        seg[i] = min(seg[i<<1], seg[i<<1|1]);

    auto query = [&](int l, int r) {
        int res = m;
        for(l += m, r += m; l < r; l >>= 1, r >>= 1) {
            if(l&1) res = min(res, seg[l++]);
            if(r&1) res = min(res, seg[--r]);
        } return res;
    };

    string ans;
    while(Q--) {
        int l, r; cin >> l >> r; l--;
        ans += query(l, r) < r? '1' : '0';
    } cout << ans << '\n';
}