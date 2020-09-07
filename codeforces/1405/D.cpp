/**
 🍪 thew6rst
 🍪 07.09.2020 09:46:21
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

int the_real_main() {
    int i, n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--; b--;
    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    bool first_turn = false;
    Y([&](auto self, int v, int p, int d) -> void {
    	if(v == b and d <= da) first_turn = true;
        for(auto& x: g[v]) {
            if(x == p) continue; 
            self(x, v, d+1);
        }
    })(a, -1, 0);

    vector<int> d(n);
    auto bfs = [&] (int root) {
        queue<int> q;
        q.push(root);
        d[root] = 1;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(auto nxt : g[cur]) {
                if(!d[nxt]) {
                    d[nxt] = d[cur] + 1;
                    q.push(nxt);
                }
            }
        }
    };

    bfs(0);
    int mxd = -1, nxt;
    for(i = 0; i < n; i++) 
        if(chmax(mxd, d[i])) nxt = i;
    d.assign(n, 0);
    bfs(nxt);
    mxd = *max_element(all(d)) - 1;
    cout << (first_turn or min(mxd, db) <= 2*da? "Alice" : "Bob") << endl;
    return 0;
}

int32_t main() {
    aylmao
    int Q; for(cin >> Q; Q; Q--) the_real_main();
    return 0;
}