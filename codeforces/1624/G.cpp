/**
 🍪 the_hyp0cr1t3
 🍪 10.01.2022 20:20:55
**/
#ifdef W
    #include <k_II.h>
    #undef e
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

struct edge_t {
    int u{-1}, v{-1}; int64_t w{0};
    edge_t() = default;
    edge_t(int u, int v, int64_t w = 0) : u(u), v(v), w(w) {}
    bool operator<(const edge_t& other) { return w < other.w; }
    friend ostream& operator<<(ostream& os, const edge_t& e) { os << e.u << ' ' << e.v << ' ' << e.w; return os; }
};

struct DSU {
    int n, components;
    vector<int> data, rootID, roots;

    DSU(int n): n(n), components(n), data(n + 1, -1) {}

    int par(int x) {
        return data[x] < 0? x : data[x] = par(data[x]);
    }

    int SZ(int x) {
        return -data[par(x)];
    }

    bool merge(int x, int y) {
        x = par(x); y = par(y);
        if(x == y) return false;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x; components--;
        return true;
    }

};


int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int LG = 31;

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, n, m, ans = 0;
        cin >> n >> m;
        vector<edge_t> edges(m);
        for(auto& e: edges)
            cin >> e.u >> e.v >> e.w;

        auto cur = views::all(edges);
        for(int b = LG; ~b; b--) {
            DSU dsu(n);
            vector<edge_t> nedges;
            nedges.reserve(m);
            for(auto& e: edges) {
                if(~e.w >> b & 1) {
                    nedges.push_back(e);
                    dsu.merge(e.u, e.v);
                }
            }

            if(dsu.components == 1)
                edges = nedges;
        }

        DSU dsu(n);
        for(auto& e: edges)
            if(dsu.merge(e.u, e.v)) ans |= e.w;

        cout << ans << '\n';
    }();

} // ~W