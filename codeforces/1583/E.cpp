/**
 🍪 the_hyp0cr1t3
 🍪 18.10.2021 23:31:31
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n, m, q;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    vector<int> vis(n), par(n, -1), depth(n), ed(n);
    Y([&](auto dfs, int v, int p) -> void {
        vis[v] = true; par[v] = p;
        for(auto& x: g[v])
            if(!vis[x]) depth[x] = depth[v] + 1, dfs(x, v);
    })(0, -1);

    vector<list<int>> ans;
    ans.reserve(q);
    cin >> q;
    while(q--) {
        int u, v; cin >> u >> v; --u; --v;
        list<int> fwd, rev;
        while(depth[u] > depth[v]) {
            fwd.push_back(u);
            ed[u] ^= 1; u = par[u];
        }

        while(depth[v] > depth[u]) {
            rev.push_back(v);
            ed[v] ^= 1; v = par[v];
        }

        while(u ^ v) {
            fwd.push_back(u);
            rev.push_back(v);
            ed[u] ^= 1; u = par[u];
            ed[v] ^= 1; v = par[v];
        }

        fwd.push_back(u);

        reverse(rev.begin(), rev.end());
        fwd.splice(fwd.end(), rev);

        ans.emplace_back(std::move(fwd));
    }

    if(count(ed.begin(), ed.end(), 1)) {
        cout << "nO" << '\n';

        int ans = 0; vis.assign(n, false);
        Y([&](auto dfs, int v, int p) -> void {
            int cnt = 0;
            vis[v] = true;
            for(auto& x: g[v]) if(!vis[x]) {
                dfs(x, v);
                cnt += ed[x];
            }

            ans += cnt + !ed[v] >> 1;
        })(0, -1);

        cout << ans << '\n';
    } else {
        cout << "yEs" << '\n';
        for(auto& x: ans) {
            cout << x.size() << '\n';
            for(auto& y: x) cout << y + 1 << ' ';
            cout << '\n';
        }
    }
} // ~W