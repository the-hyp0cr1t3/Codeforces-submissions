/**
 🍪 the_hyp0cr1t3
 🍪 11.01.2022 17:23:54
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

// 0-indexed, (i, ¬i) represented by (i << 1, i << 1 | 1)
struct TwoSAT {
    int N;
    vector<int> comp, order, assignment;
    vector<vector<int>> g, rg;

    TwoSAT(int n): N(n), comp(n << 1, -1), g(n << 1), rg(n << 1), assignment(n) {}

    void implies(int p, int q) { g[p].push_back(q); rg[q].push_back(p); };    // p → q
    void add_or (int p, int q) { implies(p ^ 1, q); implies(q ^ 1, p); };     // p ∨ q ≡ (¬p → q) ∧ (¬q → p)
    void add_xor(int p, int q) { add_or(p, q); add_or(p ^ 1, q ^ 1); };       // p ⊕ q ≡ (p ∨ q) ∧ (¬p ∨ ¬q)
    void add_bicond(int p, int q) { add_xor(p, q ^ 1); };                     // p ↔ q ≡ (p → q) ∧ (q → p) ≡ (p ⊕ ¬q)
    void add_truth(int p) { implies(p ^ 1, p); }                              // p ≡ ¬p → p

    bool is_sat() {
        order.reserve(N << 1);
        for(int i = 0; i < N << 1; i++)
            if(comp[i] == -1) dfs(i, -2, g);

        reverse(order.begin(), order.end());
        comp.assign(N << 1, -1);

        int _ = 0;
        for(auto& v: order)
            if(comp[v] == -1) dfs(v, _++, rg);

        bool bad = false;
        for(int i = 0; i < N; i++) {
            if(comp[i << 1] == comp[i << 1 | 1]) bad = true;
            assignment[i] = comp[i << 1] > comp[i << 1 | 1];
        }

        return !bad;
    }

    void dfs(int v, int k, const vector<vector<int>>& gr) {
        comp[v] = k;
        for(auto& x: gr[v])
            if(comp[x] == -1) dfs(x, k, gr);
        if(k == -2) order.push_back(v);
    };

};

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, n, m;
        cin >> n >> m;
        TwoSAT sat(n);
        sat.add_truth(0 << 1);

        vector<vector<pair<int, int>>> g(n);
        for(i = 0; i < n - 1; i++) {
            int u, v, w; cin >> u >> v >> w;
            g[--u].emplace_back(--v, w);
            g[v].emplace_back(u, w);
            if(~w) __builtin_popcount(w) & 1? sat.add_xor(u << 1, v << 1)
                                                : sat.add_bicond(u << 1, v << 1);
        }

        while(m--) {
            int a, b, p; cin >> a >> b >> p;
            --a; --b;
            p? sat.add_xor(a << 1, b << 1) : sat.add_bicond(a << 1, b << 1);
        }

        if(!sat.is_sat())
            return cout << "nO" << '\n', 0;

        cout << "yEs" << '\n';
        Y([&](auto dfs, int v, int p) -> void {
            for(auto& [x, w]: g[v]) if(x ^ p) {
                cout << v + 1 << ' ' << x + 1 << ' '
                        << (~w? w : sat.assignment[v] ^ sat.assignment[x]) << '\n';
                dfs(x, v);
            }
        })(0, -1);

        return 0;
    }();

} // ~W