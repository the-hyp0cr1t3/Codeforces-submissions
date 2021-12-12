/**
 🍪 the_hyp0cr1t3
 🍪 12.12.2021 21:52:44
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

    static int ceil2n(int x) {
        return (1 << 31 - __builtin_clz(x << 1) + !!(x & x-1)) + 2;
    }

    template<class It>
    void build(int node, int L, int R, It beg, It end, bool opt) {
        if(L == R) return st[node] = static_cast<T>(*beg), void();
        int M = L + R >> 1;
        build(node << 1, L, M, beg, beg + (opt? M - L : 0), opt);
        build(node << 1 | 1, M + 1, R, beg + (opt? M - L + 1 : 0), end, opt);
        st[node] = T(st[node << 1], st[node << 1 | 1]);
    }

    T Query(int node, int L, int R, int ql, int qr) {
        if(ql == L and R == qr) return st[node];
        int M = L + R >> 1;
        return qr <= M? Query(node << 1, L, M, ql, qr)
                        : M < ql? Query(node << 1 | 1, M + 1, R, ql, qr)
                            : T(Query(node << 1, L, M, ql, M),
                                    Query(node << 1 | 1, M + 1, R, M + 1, qr));
    }

    int Queryk(int node, int L, int R, int k) {
        if(L == R) return st[node] >= k? L : -1;
        int M = L + R >> 1;
        return k <= st[node << 1]? Queryk(node << 1, L, M, k)
                        : Queryk(node << 1 | 1, M + 1, R, k - st[node << 1]);
    }

    void Update(int node, int L, int R, int pos, int64_t val) {
        if(L == R) return st[node].upd(val);
        int M = L + R >> 1;
        pos <= M? Update(node << 1, L, M, pos, val)
                    : Update(node << 1 | 1, M + 1, R, pos, val);
        st[node] = T(st[node << 1], st[node << 1 | 1]);
    }

public:

    template<class... Args>
    Segtree(int N, Args&&... args): N(N), st(ceil2n(N)) {
        T val(forward<Args>(args)...); build(1, ONE, N - !ONE, &val, &val, false);
    }

    template<typename It,
        typename = enable_if_t<is_same<typename iterator_traits<It>::iterator_category,
                                            random_access_iterator_tag>::value,
                                typename iterator_traits<It>::difference_type>>
    Segtree(It beg, It end): N(end - beg), st(ceil2n(N)) {
        build(1, ONE, N - !ONE, beg, end, true);
    }

    T query(int pos) { return Query(1, ONE, N - !ONE, pos, pos); }
    T query(int l, int r) { if(l > r) return T(); return Query(1, ONE, N - !ONE, l, r); }
    int queryk(int k) { return Queryk(1, ONE, N - !ONE, k); }
    void update(int pos, int64_t val) { if(!pos) return; Update(1, ONE, N - !ONE, pos, val); }

};

struct Node {
    int val;
    Node(int val = 0): val(val) {}
    Node(const Node& l, const Node& r)
        : val(l.val + r.val) {}
    void upd(int delta) { val += delta; }
    operator int() const { return val; }
};

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) []() {
        int i, n, q;
        cin >> n >> q;
        vector<int> a(n), ans(q);
        for(auto& x: a) cin >> x, --x;
        vector<vector<int>> g(n);
        for(i = 1; i < n; i++) {
            int p; cin >> p;
            g[--p].push_back(i);
        }

        vector<vector<tuple<int, int, int>>> queries(n);
        for(i = 0; i < q; i++) {
            int v, l, k;
            cin >> v >> l >> k;
            queries[--v].emplace_back(l, k, i);
        }

        Segtree<Node> cnt(n);
        vector<int> frq(n);
        vector<set<int>> val(n + 1);
        for(i = 0; i < n; i++)
            val[0].insert(i);

        auto apply = [&](int x, int delta) {
            val[frq[x]].erase(x);
            cnt.update(frq[x], -1);

            frq[x] += delta;

            val[frq[x]].insert(x);
            cnt.update(frq[x], +1);
        };

        Y([&](auto dfs, int v, int p) -> void {
            apply(a[v], +1);
            for(auto& [l, k, idx]: queries[v]) {
                auto x = cnt.queryk(k + cnt.query(1, l - 1));
                ans[idx] = ~x? *val[x].begin() + 1 : x;
            }
            for(auto& x: g[v])
                if(x ^ p) dfs(x, v);
            apply(a[v], -1);
        })(0, -1);

        for(auto& x: ans)
            cout << x << ' ';
        cout << '\n';
    }();

} // ~W