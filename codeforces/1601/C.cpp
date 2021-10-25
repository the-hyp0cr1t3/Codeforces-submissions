/**
 🍪 the_hyp0cr1t3
 🍪 25.10.2021 13:26:35
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

template<class T, bool ONE = true, class U = int64_t>
class Segtree {
    struct Node {
        bool pending{false};
        T info; U lazy{};
    };

    using V = pair<int, T>;

    int N; vector<Node> st;

    static int ceil2n(int x) {
        return (1 << 31 - __builtin_clz(x << 1) + !!(x & x-1)) + 2;
    }

    template<class It>
    void build(int node, int L, int R, It beg, It end, bool opt) {
        if(L == R) return st[node].info = static_cast<T>(*beg), void();
        int M = L + R >> 1;
        build(node << 1, L, M, beg, beg + (opt? M - L : 0), opt);
        build(node << 1 | 1, M + 1, R, beg + (opt? M - L + 1 : 0), end, opt);
        st[node].info = T(st[node << 1].info, st[node << 1 | 1].info);
    }

    void prop(int node, int L, int R) {
        if(L != R) {
            st[node << 1].pending = st[node << 1 | 1].pending = true;
            st[node << 1].lazy += st[node].lazy;
            st[node << 1 | 1].lazy += st[node].lazy;
        }
        st[node].info.apply_lazy(st[node].lazy, R - L + 1);
        st[node].pending = false; st[node].lazy = U();
    }

    T Query(int node, int L, int R) {
        if(st[node].pending) prop(node, L, R);
        if(L == R) return st[node].info;

        int M = L + R >> 1;
        if(st[node << 1].pending) prop(node << 1, L, M);
        if(st[node << 1 | 1].pending) prop(node << 1 | 1, M + 1, R);

        return st[node << 1].info.val <= st[node << 1 | 1].info.val?
                    Query(node << 1, L, M) : Query(node << 1 | 1, M + 1, R);
    }

    void Update(int node, int L, int R, int ul, int ur, const U& val) {
        if(st[node].pending) prop(node, L, R);
        if(ur < ul) return;
        if(ul == L and R == ur)
            return st[node].lazy += val, prop(node, L, R);
        int M = L + R >> 1;
        Update(node << 1, L, M, ul, min(ur, M), val);
        Update(node << 1 | 1, M + 1, R, max(M + 1, ul), ur, val);
        st[node].info = T(st[node << 1].info, st[node << 1 | 1].info);
    }


public:

    template<class... Args>
    Segtree(int N, Args&&... args)
        : N(N), st(ceil2n(N)) {
            T val(forward<Args>(args)...); build(1, ONE, N - !ONE, &val, &val, false);
    }

    template<typename It,
        typename = enable_if_t<is_same<typename iterator_traits<It>::iterator_category,
                                            random_access_iterator_tag>::value,
                                typename iterator_traits<It>::difference_type>>
    Segtree(It beg, It end)
        : N(end - beg), st(ceil2n(N)) {
            build(1, ONE, N - !ONE, beg, end, true);
    }

    T query() { return Query(1, ONE, N - !ONE); }

    template<class... Args>
    void update(int ul, int ur, Args&&... args) {
        U val(forward<Args>(args)...);
        Update(1, ONE, N - !ONE, ul, ur, val);
    }

    template<class... Args>
    void update_pt(int pos, Args&&... args) {
        update(pos, pos, forward<Args>(args)...);
    }

};

struct Node {
    int64_t val;
    Node(int64_t val = 0): val(val) {}
    Node(const Node& l, const Node& r)
        : val(min(l.val, r.val)) {}
    void apply_lazy(int32_t delta, int32_t len) { val += delta; }
    operator int64_t() const { return val; }
};

template <class T>
struct BIT {
    int N; vector<T> bit;
    BIT(int N): N(N), bit(N + 1) {}

    BIT(const vector<T>& a) : N(a.size()), bit(N + 1) {
        for(int i = 1; i <= N; i++) {
            bit[i] += a[i-1];
            if(i + (i & -i) <= N)
                bit[i + (i & -i)] += bit[i];
        }
    }

    T query(int i) {
        T res = 0;
        for(i++; i; i -= i & -i)
            res += bit[i];
        return res;
    }

    void update(int i, T val) {
        for(i++; i <= N; i += i & -i)
            bit[i] += val;
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) []() {
        int i, j, n, m; int64_t ans = 0;
        cin >> n >> m;
        vector<int> a(n), b(m), c;
        c.reserve(n + m);
        for(auto& x: a) cin >> x, c.push_back(x);
        for(auto& x: b) cin >> x, c.push_back(x);

        ranges::sort(b);
        ranges::sort(c);
        c.erase(unique(c.begin(), c.end()), c.end());
        int z = c.size();

        vector<int> frq(z);
        vector<vector<int>> occ(z);
        for(i = 1; auto& x: a) {
            frq[x = ranges::lower_bound(c, x) - c.begin()]++;
            occ[x].push_back(i++);
        }
        for(auto& x: b)
            x = ranges::lower_bound(c, x) - c.begin();

        BIT<int> pref(z), suf(frq);
        vector<int64_t> v(n + 1);
        v[0] = suf.query(b[0] - 1);
        for(i = 1; auto& x: a) {
            ans += suf.query(x - 1);
            pref.update(x, +1); suf.update(x, -1);
            v[i++] = pref.query(z - 1) - pref.query(b[0]) + suf.query(b[0] - 1);
        }

        Segtree<Node, 0> seg(v.begin(), v.end());
        int64_t prv = seg.query();
        ans += prv;

        for(i = 1; i < m; i++) {
            if(b[i] == b[i - 1]) {
                ans += prv;
                continue;
            }

            for(auto x: occ[b[i - 1]])
                seg.update(0, x - 1, +1);

            for(auto x: occ[b[i]])
                seg.update(x, n, -1);

            for(j = b[i - 1] + 1; j < b[i]; j++) {
                for(auto x: occ[j]) {
                    seg.update(0, x - 1, +1);
                    seg.update(x, n, -1);
                }
            }

            ans += (prv = seg.query());
        }

        cout << ans << '\n';
    }();

} // ~W