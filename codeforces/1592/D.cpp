/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2021 23:16:05
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
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int i, n;
    cin >> n;
    vector<vector<int>> g(n);
    for(i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    vector<int> order, par(n, -1);
    Y([&](auto dfs, int v, int p) -> void {
        order.push_back(v);
        par[v] = p;
        for(auto& x: g[v]) if(x ^ p) {
            dfs(x, v);
        }
    })(0, -1);

    auto query = [&](int x) {
        cout << "? " << x + 1;
        for(i = 0; i <= x; i++)
            cout << ' ' << order[i] + 1;
        cout << endl;
        return cin >> x, x;
    };

    int mx = query(n - 1);
    int lo = 1, hi = n - 1;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(query(mid) == mx) hi = mid - 1;
        else lo = mid + 1;
    }

    cout << "! " << par[order[lo]] + 1 << ' ' << order[lo] + 1 << endl;
} // ~W