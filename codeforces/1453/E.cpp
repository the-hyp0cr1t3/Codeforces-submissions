/**
 🍪 the_hyp0cr1t3
 🍪 05.12.2020 21:37:16
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

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

int ocoiek() {
    int i, n, ans = 0;
    cin >> n;
    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v); g[v].pb(u);
    }
    
    cout << Y([&](auto self, int v, int p) -> int {
        if(v and sz(g[v]) == 1) return 0;
        vector<int> ds; ds.reserve(sz(g[v]));
        for(auto& x: g[v]) {
            if(x == p) continue; 
            ds.pb(self(x, v) + 1);
        } sort(all(ds));
        if(v) {
            chmax(ans, ds.back()+1);
            return ds[0];
        } else {
            chmax(ans, ds.back());
            ds.pop_back();
            if(!empty(ds)) chmax(ans, ds.back()+1);
            return ans;
        }     
    })(0, -1) << '\n';

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W 