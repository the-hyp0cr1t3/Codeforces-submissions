/**
 🍪 the_hyp0cr1t3
 🍪 14.09.2020 01:56:31
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

int32_t main() {
    aylmao
    int i, n, k; ll ans = 0;
    cin >> n >> k;
    vector<int> sub(n);
    for(i = 0; i < 2*k; i++) {
        int a; cin >> a; sub[--a] = 1;
    }
    
    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    Y([&](auto self, int v, int p) -> void {
        for(auto& x: g[v]) { 
            if(x == p) continue; 
            self(x, v);
            sub[v] += sub[x];
            ans += min(sub[x], 2*k - sub[x]);
        }
   })(0, -1);

   cout << ans << '\n';
}