/**
 🍪 the_hyp0cr1t3
 🍪 26.10.2021 02:08:53
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

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
    T query(int l, int r) { return Query(1, ONE, N - !ONE, l, r); }
    void update(int pos, int64_t val) { Update(1, ONE, N - !ONE, pos, val); }

};

struct Node {
    static const int64_t INF = 1e18;
    int64_t mn{ INF }, mx{ -INF };
    Node() = default;
    Node(int64_t x): mn(x), mx(x) {}
    Node(const Node& l, const Node& r)
        : mn(min(l.mn, r.mn)), mx(max(l.mx, r.mx)) {}
    void upd(int64_t delta) {}
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    namespace r = ranges; namespace v = views;
    int i, n, q;
    cin >> n >> q;
    vector<int64_t> a(n);
    for(auto& x: a) cin >> x;
    for(auto& x: a) cin >> i, x -= i;
    a.insert(a.begin(), 0);
    partial_sum(a.begin(), a.end(), a.begin());

    Segtree<Node> seg(a.begin() + 1, a.end());
    while(q--) {
        int l, r; cin >> l >> r;
        auto x = seg.query(l, r);
        if(a[r] - a[l - 1] or x.mx - a[l - 1] > 0)
            cout << -1 << '\n';
        else
            cout << a[l - 1] - x.mn << '\n';
    }

} // ~W