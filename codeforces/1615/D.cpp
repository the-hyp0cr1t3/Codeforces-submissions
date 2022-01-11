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

// 0-indexed, (i, ¬i) represented by (i, i + n)
class TwoSAT {
    int N;
    vector<int> comp, order;
    vector<vector<int>> g, rg;

    int complement(int i) { return i < N? i + N : i - N; }

    void dfs(int v, int k, const vector<vector<int>>& gr) {
        comp[v] = k;
        for(auto& x: gr[v])
            if(comp[x] == -1) dfs(x, k, gr);
        if(k == -2) order.push_back(v);
    };

public:

    TwoSAT(int n): N(n), comp(n << 1, -1), g(n << 1), rg(n << 1) {}

    // p, q ∈ [0, 2n)
    void implies(int p, int q) { g[p].push_back(q); rg[q].push_back(p); };                  // p → q
    void add_truth(int p) { implies(complement(p), p); }                                    // p ≡ ¬p → p
    void add_or (int p, int q) { implies(complement(p), q); implies(complement(q), p); };   // p ∨ q ≡ (¬p → q) ∧ (¬q → p)
    // p, q ∈ [0, n)
    void add_xor(int p, int q) { add_or(p, q); add_or(complement(p), complement(q)); };     // p ⊕ q ≡ (p ∨ q) ∧ (¬p ∨ ¬q)
    void add_bicond(int p, int q) { add_xor(p, complement(q)); };                           // p ↔ q ≡ (p → q) ∧ (q → p) ≡ (p ⊕ ¬q)

    bool is_sat() {
        order.reserve(N << 1);
        for(int i = 0; i < N << 1; i++)
            if(comp[i] == -1) dfs(i, -2, g);

        reverse(order.begin(), order.end());
        comp.assign(N << 1, -1);

        int _ = 0;
        for(auto& v: order)
            if(comp[v] == -1) dfs(v, _++, rg);

        for(int i = 0; i < N; i++)
            if(comp[i] == comp[i + N]) return false;

        return true;
    }

    vector<int> get_assignment() {
        vector<int> assn(N);
        for(int i = 0; i < N; i++)
            assn[i] = comp[i] > comp[i + N];
        return assn;
    }

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
        vector<tuple<int, int, int>> edges(n - 1);
        for(auto& [u, v, w]: edges) {
            cin >> u >> v >> w; --u, --v;
            if(~w) __builtin_popcount(w) & 1? sat.add_xor(u, v) : sat.add_bicond(u, v);
        }

        while(m--) {
            int a, b, p; cin >> a >> b >> p; --a; --b;
            p? sat.add_xor(a, b) : sat.add_bicond(a, b);
        }

        if(!sat.is_sat())
            return cout << "nO" << '\n', 0;

        auto assn = sat.get_assignment();

        cout << "yEs" << '\n';
        for(auto& [u, v, w]: edges)
            cout << u + 1 << ' ' << v + 1 << ' ' << (~w? w : assn[u] ^ assn[v]) << '\n';

        return 0;
    }();

} // ~W