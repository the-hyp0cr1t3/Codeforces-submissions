/**
 🍪 thew6rst
 🍪 13.09.2020 18:50:12
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define endl '\n'
#define pb emplace_back
// #define int int64_t
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
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
int n;

int32_t main() {
    aylmao
    int i, Q;
    cin >> n >> Q;
    vector<ll> a(n);
    for(i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    vector<int> d(n), tree{-1}, sub(n, 1), tin(n); 
    tree.reserve(n+1);
    Y([&](auto self, int v, int p, int depth = 0) -> void {
        d[v] = depth; tin[v] = sz(tree); tree.pb(v);
        for(auto& x: g[v]) { 
            if(x == p) continue;
            self(x, v, depth+1);
            sub[v] += sub[x];
        }
    })(0, -1);
    
    int m = 1; while(m < 2*n) m <<= 1;
    vector<ll> lazy(m);

    auto prop = [&](int node, int L, int R) {
        if(L == R) a[tree[L]] += d[tree[L]]&1? -lazy[node] : lazy[node];
        else lazy[node<<1] += lazy[node], lazy[node<<1|1] += lazy[node];
        lazy[node] = 0;
    };

    auto update = Y([&](auto self, int l, int r, ll val, int node = 1, int L = 1, int R = ::n) -> void {
        if(lazy[node]) prop(node, L, R);
        if(l > R or r < L) return;
        if(l <= L and R <= r) return lazy[node] += val, void();
        int M = L + R >> 1;
        self(l, r, val, node << 1, L, M);
        self(l, r, val, node << 1 | 1, M + 1, R);
    });

    auto query = Y([&](auto self, int pos, int node = 1, int L = 1, int R = ::n) -> ll {
        if(lazy[node]) prop(node, L, R);
        if(L == R) return a[tree[L]];
        int M = L + R >> 1;
        return pos <= M? self(pos, node << 1, L, M) : self(pos, node << 1 | 1, M + 1, R);
    });

    while(Q--) {
        int o, x; cin >> o >> x; x--;
        if(o == 1) {
            int val; cin >> val;
            update(tin[x], tin[x] + sub[x] - 1, d[x]&1? -val : val);
        } else
            cout << query(tin[x]) << '\n';
    }
}