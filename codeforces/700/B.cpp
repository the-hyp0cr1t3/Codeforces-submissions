/**
 🍪 the_hyp0cr1t3
 🍪 14.09.2020 02:04:52
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
int lg2[2*N];

int32_t main() {
    aylmao
    int i, n, K; ll ans = 0;
    cin >> n >> K;
    vector<int> unis(2*K);
    for(auto& x: unis) cin >> x, --x;
    
    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    for(lg2[0] = -1, i = 1; i < 2*n; i++) 
        lg2[i] = lg2[i/2] + 1;
    
    int len = 2*n-1, j, k;
    int b = max(1, lg2[len]/2);
    int cntb = (len+b-1)/b;
    
    vector<int> tin(n), d(n), bmask(cntb), tree;
    vector<vector<int>> sparse(lg2[cntb]+1, vector<int>(cntb));
    vector<vector<vector<int>>> best(1<<b-1);
    tree.reserve(2*n);
    
    Y([&](auto dfs, int v, int p) -> void {
        tin[v] = sz(tree);
        tree.pb(v);
        for(auto x: g[v]) { 
            if(x == p) continue;
            d[x] = d[v] + 1;
            dfs(x, v);
            tree.pb(v);
        }    
    })(0, -1);
    
    auto lower = [&](int p, int q) {
        return d[tree[p]] < d[tree[q]]? p : q;
    };
    
    for(i = 0; i < len; i++) {
        int curb = i/b; j = i%b;
        if(!j or lower(sparse[0][curb], i) == i)
            sparse[0][curb] = i;
        if(j and lower(i-1, i) == i-1)
            bmask[curb] |= 1<<j-1;
    }
    
    for(k = 1; k <= lg2[cntb]; k++) {
        for(i = 0; i < cntb; i++) {
            j = i + (1<<k-1);
            sparse[k][i] = sparse[k-1][i];
            if(j < cntb)
                sparse[k][i] = lower(sparse[k-1][i], sparse[k-1][j]);
        }
    }
    
    for(int curb = 0; curb < cntb; curb++) {
        int mask = bmask[curb];
        if(sz(best[mask])) continue;
        best[mask].resize(b, vector<int>(b));
        for(i = 0; i < b; i++) {
            best[mask][i][i] = i;
            for(j = i+1; j < b; j++) {
                if(b*curb+j >= len) break;
                best[mask][i][j] = lower(b*curb+best[mask][i][j-1], b*curb+j);
                best[mask][i][j] -= b*curb;
            }
        }
    }
    
    auto geti = [&](int curb, int l, int r) {
        return best[bmask[curb]][l][r] + b*curb;
    };
    
    auto LCA = [&](int u, int v) {
        u = tin[u];
        v = tin[v];
        if(u > v) swap(u, v);
        int bu = u/b, bv = v/b;
        if(bu == bv)
            return tree[geti(bu, u%b, v%b)];
        int res = lower(geti(bu, u%b, b-1), geti(bv, 0, v%b));
        if(bv-bu > 1) {
            int z = lg2[bv-bu-1];
            res = lower(res, lower(sparse[z][bu+1], sparse[z][bv-(1<<z)]));
        }
        return tree[res];
    };

    auto dist = [&](int u, int v) {
        return d[u] + d[v] - 2*d[LCA(u, v)];
    };
    
    sort(all(unis), [&](const auto& A, const auto& B) { 
        return tin[A] < tin[B];
    });

    for(i = 0; i < K; i++)
        ans += dist(unis[i], unis[i+K]);

    cout << ans << '\n';
}