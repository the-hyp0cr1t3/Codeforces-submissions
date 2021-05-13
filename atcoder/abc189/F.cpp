/**
 🍪 the_hyp0cr1t3
 🍪 13.05.2021 16:27:54
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

template<class T, class U = double>
struct Segtree {
    int N; vector<T> st;
    Segtree(int N)
        : N(N), st(ceil2n(N)) {}
    template<class Iter> Segtree(Iter beg, Iter end)
        : Segtree(end-beg) { build(1, 1, N, beg, end); }
    static int ceil2n(int x) {
        return (1 << 31 - __builtin_clz(x << 1) + !!(x & x-1)) + 2;
    }

    template<class Iter>
    void build(int node, int L, int R, Iter beg, Iter end) {
        if(L == R) return st[node].set(*beg);
        int M = L + R >> 1;
        build(node<<1, L, M, beg, beg+(M-L));
        build(node<<1|1, M+1, R, beg+(M-L+1), end);
        st[node] = T(st[node<<1], st[node<<1|1]);
    }

    T Query(int node, int L, int R, int i, int j) {
        if(i > R or j < L) return T();
        if(i <= L and j >= R) return st[node];
        int M = L + R >> 1;
        return T(Query(node<<1, L, M, i, j), 
                    Query(node<<1|1, M+1, R, i, j));
    } 

    void Update(int node, int L, int R, int pos, double val) {
        if(L == R) return st[node].upd(val);
        int M = L + R >> 1;
        pos <= M? Update(node<<1, L, M, pos, val)
                    : Update(node<<1|1, M+1, R, pos, val);
        st[node] = T(st[node<<1], st[node<<1|1]);
    }

    auto query(int pos) { return Query(1, 1, N, pos, pos); }
    auto query(int l, int r) { return Query(1, 1, N, l, r); }
    void update(int pos, double val) { Update(1, 1, N, pos, val); }
};

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m, k;
    cin >> n >> m >> k;
    
    vector<bool> istrap(n+3);
    for(i = 0; i < k; i++) {
        int x; cin >> x;
        istrap[x+1] = true;
    }

    int max_trap_len = 0, cur_len = 0;
    for(i = 0; i <= n; i++) {
        if(istrap[i]) cur_len++;
        else cur_len = 0;
        max_trap_len = max(max_trap_len, cur_len);
    }

    if(max_trap_len >= m)
        return cout << -1 << '\n', 0;


    struct Node {
        double val{0};
        Node() = default;
        Node(const Node& l, const Node& r)
            : val(l.val + r.val) {}
        void set(double init) { val = init; }
        void upd(double delta) { val += delta; }
        operator double() const { return val; }
    };

    Segtree<Node> seg(n+m), zero(n+m);
    for(i = n; i; i--) {
        if(istrap[i]) {
            zero.update(i, 1);
        } else {
            seg.update(i, 1.0 + seg.query(i+1, i+m) / m);
            zero.update(i, zero.query(i+1, i+m) / m);
        }
    }

    cout.precision(10);
    cout << seg.query(1) / (1.0 - zero.query(1));
} // ~W 