/**
 🍪 the_hyp0cr1t3
 🍪 13.09.2020 23:10:33
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int N = 2e5 + 5;
const int LG = 20;

int32_t main() {
    aylmao
    int i, n, tim = 0;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> roots; roots.reserve(n);
    for(i = 0; i < n; i++) {
        int u; cin >> u; u--;
        if(~u) g[u].pb(i);
        else roots.pb(i);
    }
    
    vector<vector<int>> d(n), anc(LG, vector<int>(n, -1));
    vector<int> tin(n), tout(n), depth(n);
    auto dfs = Y([&](auto self, int v, int p, int k = 0) -> void {
        tin[v] = tim++; d[k].pb(v);
        anc[0][v] = p; depth[v] = k;
        for(i = 1; i < LG; i++)
            if(~anc[i-1][v]) 
                anc[i][v] = anc[i-1][anc[i-1][v]];
        for(auto& x: g[v])
            self(x, v, k+1);
        tout[v] = tim++;
    });

    for(auto v: roots) dfs(v, -1);

    auto walk = [&](int v, int dist) {
        for(i = 0; i < LG; i++)
            if(~v and dist >> i & 1) v = anc[i][v];
        return v;
    };

    auto binsearch = [&](int k, int lo, int hi, int t) {
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if(tin[d[k][mid]] <= t) lo = mid + 1;
            else hi = mid -1;
        } return lo;
    };

    auto get = [&](int in, int out, int k) {
        int x = binsearch(k, 0, sz(d[k])-1, in-1);
        int y = binsearch(k, x, sz(d[k])-1, out);
        return y - x;
    };

    int Q; cin >> Q;
    while(Q--) {
        int v, p; cin >> v >> p; v--;
        int z = walk(v, p);
        if(z == -1) {
            cout << 0 << " ";
            continue;
        }
        int ans = get(tin[z], tout[z], depth[v]) - 1;
        cout << ans << " ";
    } cout << '\n';
}