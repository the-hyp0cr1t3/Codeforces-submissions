/**
 🍪 the_hyp0cr1t3
 🍪 20.11.2021 15:40:02
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

    void Update(int node, int L, int R, int pos) {
        if(L == R) return st[node] = T(pos), void();
        int M = L + R >> 1;
        pos <= M? Update(node << 1, L, M, pos)
                    : Update(node << 1 | 1, M + 1, R, pos);
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
    void update(int pos) { Update(1, ONE, N - !ONE, pos); }

};

int a[200'000 + 5];

struct Node {
    static const int INF = 1e9;
    int64_t cnt;
    int lpos, rpos, lpeak, rpeak;
    Node(int pos = 0): lpos(pos), rpos(pos), lpeak(INF), rpeak(-INF), cnt(!!pos) {}
    Node(const Node& l, const Node& r) {
        cnt = l.cnt + r.cnt;
        lpos = l.lpos;
        rpos = r.rpos;
        lpeak = min(l.lpeak, r.lpeak);
        rpeak = max(r.rpeak, l.rpeak);
        if(a[l.rpos] <= a[r.lpos]) {
            cnt += 1LL * (l.rpos - (l.rpeak == -INF? l.lpos : l.rpeak) + 1)
                            * ((r.lpeak == INF? r.rpos + 1 : r.lpeak) - r.lpos);
        } else {
            lpeak = min(lpeak, r.lpos);
            rpeak = max(rpeak, r.lpos);
        }
    }
    operator int64_t() const { return cnt; }
};

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int i, n, q;
    cin >> n >> q;
    for(i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> _(n);
    iota(_.begin(), _.end(), 1);

    Segtree<Node> seg(_.begin(), _.end());
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int pos, val; cin >> pos >> val;
            a[pos] = val; seg.update(pos);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.query(l, r) << '\n';
        }
    }

} // ~W