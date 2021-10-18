/**
 🍪 the_hyp0cr1t3
 🍪 18.10.2021 22:25:19
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
    int val;
    Node(int val = -1): val(val) {}
    Node(const Node& l, const Node& r)
        : val(max(l.val, r.val)) {}
    void upd(int delta) { val += delta; }
    operator int() const { return val; }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, j, n, m, q;
    cin >> n >> m;
    vector<string> a(n);
    for(auto& x: a) cin >> x;

    vector reach(n, vector<int>(m)), left(n, vector<int>(m, m));
    for(i = 0; i < n; i++)
        reach[i][0] = a[i][0] == '.';

    for(j = 0; j < m; j++)
        reach[0][j] = a[0][j] == '.';

    vector<int> pref(m);
    for(i = 1; i < n; i++) {
        for(j = 1; j < m; j++) {
            if(a[i][j] == '.') {
                reach[i][j] = reach[i - 1][j] | reach[i][j - 1];
                left[i][j] = min({ left[i - 1][j], left[i][j - 1], j });
                if(!reach[i][j])
                    pref[j] = max(pref[j], left[i][j]);
            } else {
                if(!reach[i - 1][j] and !reach[i][j - 1]) {
                    pref[j] = max(pref[j], min({ left[i - 1][j], left[i][j - 1], j }));
                }
            }
        }
    }

    Segtree<Node> seg(pref.begin(), pref.end());
    cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << (seg.query(l, r) < l? "yEs" : "nO") << '\n';
    }

} // ~W