/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2021 22:43:57
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

    int tests; cin >> tests;
    while(tests--) []() {
        int i, n, k, X = 0;
        cin >> n >> k;
        vector<int> a(n);
        for(auto& x: a) cin >> x, X ^= x;

        vector<list<int>> g(n);
        for(i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            g[--u].push_back(--v);
            g[v].push_back(u);
        }

        if(X == 0)
            return cout << "yEs" << '\n', 0;

        if(k == 2)
            return cout << "nO" << '\n', 0;

        int ru = -1, rv = -1;
        auto dfs = Y([&](auto dfs, int v, int p) -> int {
            int xorr = a[v];
            for(auto& x: g[v]) if(x ^ p) {
                xorr ^= dfs(x, v);
            }
            if(ru == -1 and ~p and xorr == X)
                ru = p, rv = v;
            return xorr;
        });

        dfs(0, -1);
        if(ru == -1)
            return cout << "nO" << '\n', 0;
        g[ru].erase(R::find(g[ru], rv));
        g[rv].erase(R::find(g[rv], ru));

        ru = rv = -1; dfs(0, -1);
        return cout << (~ru? "yEs" : "nO") << '\n', 0;
    }();

} // ~W