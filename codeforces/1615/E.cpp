/**
 🍪 the_hyp0cr1t3
 🍪 12.01.2022 13:43:38
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

template<class T, bool ONE = true>
class Segtree {
    int N; vector<T> st;

    template<typename A>
    void build(int node, int L, int R, const vector<A>& a) {
        if(L == R) return st[node] = static_cast<T>(a[L - ONE]), void();
        int M = L + R >> 1;
        build(node << 1, L, M, a);
        build(node << 1 | 1, M + 1, R, a);
        st[node] = T(st[node << 1], st[node << 1 | 1]);
    }

    void prop(int node, int L, int R) {
        if(L != R) {
            st[node << 1].pending = st[node << 1 | 1].pending = true;
            st[node << 1].lazy += st[node].lazy;
            st[node << 1 | 1].lazy += st[node].lazy;
        }
        st[node].apply_lazy(R - L + 1);
        st[node].pending = false; st[node].lazy = typename T::L();
    }

    void Update(int node, int L, int R, int ul, int ur, const typename T::L& val) {
        if(st[node].pending) prop(node, L, R);
        if(ur < ul) return;
        if(ul == L and R == ur)
            return st[node].lazy += val, prop(node, L, R);
        int M = L + R >> 1;
        Update(node << 1, L, M, ul, min(ur, M), val);
        Update(node << 1 | 1, M + 1, R, max(M + 1, ul), ur, val);
        st[node] = T(st[node << 1], st[node << 1 | 1]);
    }

    T Query(int node, int L, int R, int ql, int qr) {
        if(st[node].pending) prop(node, L, R);
        if(qr < ql) return T();
        if(ql == L and R == qr) return st[node];
        int M = L + R >> 1;
        return T(Query(node << 1, L, M, ql, min(qr, M)),
                    Query(node << 1 | 1, M + 1, R, max(M + 1, ql), qr));
    }

    int Queryk(int node, int L, int R, typename T::V val) {
        if(st[node].pending) prop(node, L, R);
        if(L == R) return val <= st[node]? L : -1;
        int M = L + R >> 1;
        if(st[node << 1].pending) prop(node << 1, L, M);
        return val <= st[node << 1]?
                    Queryk(node << 1, L, M, val)
                        : Queryk(node << 1 | 1, M + 1, R, val - st[node << 1]);
    }

public:

    template<typename A>
    Segtree(const vector<A>& a): N(a.size()) {
        st.resize((1 << 31 - __builtin_clz(N << 1) + !!(N & N-1)) + 2);
        build(1, ONE, N - !ONE, a);
    }

    template<class... Args>
    Segtree(int n, Args&&... args): Segtree(vector<T>(n, T(forward<Args>(args)...))) {}

    template<class... Args>
    void update_range(int l, int r, Args&&... args) {
        Update(1, ONE, N - !ONE, l, r, typename T::L(forward<Args>(args)...));
    }

    template<class... Args>
    void update_point(int pos, Args&&... args) {
        update_range(pos, pos, forward<Args>(args)...);
    }

    T query(int pos) { return Query(1, ONE, N - !ONE, pos, pos); }
    T query(int l, int r) { return Query(1, ONE, N - !ONE, l, r); }
    int queryk(typename T::V val) { return Queryk(1, ONE, N - !ONE, val); }

};

struct Node {
    using V = int;
    using L = int;

    bool pending{false};
    V val; int v, d; L lazy{};
    Node(V val = 0, int v = -1, int d = -1): val(val), v(v), d(d) {}
    Node(const Node& l, const Node& r) {
        tie(val, d, v) = max(tuple(l.val, l.d, l.v), tuple(r.val, r.d, r.v));
    }
    void apply_lazy(int len) { val += lazy; }
    operator V() const { return val; }
};

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int i, n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for(i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    vector<int> depth(n), tin(n), par(n, -1), sub(n, 1);
    vector<Node> a; a.reserve(n);
    Y([&, t = 0](auto dfs, int v, int p) mutable -> void {
        tin[v] = t++;
        a.emplace_back(depth[v], v, depth[v]);
        if(~p) g[v].erase(R::find(g[v], p));
        for(auto& x: g[v]) {
            depth[x] = depth[v] + 1;
            par[x] = v;
            dfs(x, v);
            sub[v] += sub[x];
        }
    })(0, -1);

    vector<int> used(n);
    Segtree<Node, 0> seg(a);
    int64_t bestb = 1LL * (n >> 1) * (n + 1 >> 1), ans = -bestb;
    for(int64_t r = 1, b = n; r <= k; r++) {
        auto res = seg.query(0, n - 1);
        for(int v = res.v; ~v and !used[v]++; v = par[v]) {
            for(auto& x: g[v]) if(!used[x])
                seg.update_range(tin[x], tin[x] + sub[x] - 1, -res.val - 1);
            seg.update_point(tin[v], - res.val - 1);
            res.val--; b--;
        }
        ans = max(ans, r * (n - r) - (b < n / 2? b * (n - b) : bestb));
    }

    cout << ans;

} // ~W