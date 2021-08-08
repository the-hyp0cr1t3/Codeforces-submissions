/**
 🍪 the_hyp0cr1t3
 🍪 08.08.2021 17:37:44
**/
#ifdef W
    #include "k_II.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n;
    cin >> n;
    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[--u].pb(--v); g[v].pb(u);
    }

    vector<int> ans;
    ans.reserve(2 * n);
    Y([&](auto dfs, int v, int p) -> void {
        ans.pb(v);
        if(~p) g[v].erase(find(all(g[v]), p));
        sort(all(g[v]));
        for(auto& x: g[v]) {
            dfs(x, v), ans.pb(v);
        }
    })(0, -1);

    for(auto& x: ans) cout << x + 1 << ' ';
} // ~W