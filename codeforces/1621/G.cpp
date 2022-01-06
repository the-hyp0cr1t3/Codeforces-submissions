/**
 🍪 the_hyp0cr1t3
 🍪 05.01.2022 19:46:54
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

template<int MOD>
struct Modint {
    using T = typename decay<decltype(MOD)>::type; T v;
    Modint(): v(0) {}
    template<typename U, typename = enable_if_t<is_integral<U>::value>>
    Modint(U v) { if(v < 0) v = v % MOD + MOD; if(v >= MOD) v %= MOD; this->v = static_cast<T>(v); }
    template<typename U, typename = enable_if_t<is_integral<U>::value>>
    explicit operator U() const { return static_cast<U>(v); }
    friend istream& operator>>(istream& in, Modint& m) { int64_t v_; in >> v_; m = Modint(v_); return in; }
    friend ostream& operator<<(ostream& os, const Modint& m) { return os << m.v; }

    static T inv(T a, T m) {
        T g = m, x = 0, y = 1;
        while(a != 0) {
            T q = g / a;
            g %= a; swap(g, a);
            x -= q * y; swap(x, y);
        } return x < 0? x + m : x;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif // x must be less than 2^32 * m
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
        asm("divl %4\n" : "=a" (quot), "=d" (rem) : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    Modint inv() const { return Modint(inv(v, MOD)); }
    Modint operator-() const { return Modint(v? MOD-v : 0); }
    Modint& operator++() { v++; if(v == MOD) v = 0; return *this; }
    Modint& operator--() { if(v == 0) v = MOD; v--; return *this; }
    Modint operator++(int) { Modint a = *this; ++*this; return a; }
    Modint operator--(int) { Modint a = *this; --*this; return a; }
    Modint& operator+=(const Modint& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Modint& operator-=(const Modint& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Modint& operator*=(const Modint& o) { v = fast_mod(uint64_t(v) * o.v); return *this; }
    Modint& operator/=(const Modint& o) { return *this *= o.inv(); }
    friend Modint operator+(const Modint& a, const Modint& b) { Modint res = a; res += b; return res; }
    friend Modint operator-(const Modint& a, const Modint& b) { Modint res = a; res -= b; return res; }
    friend Modint operator*(const Modint& a, const Modint& b) { Modint res = a; res *= b; return res; }
    friend Modint operator/(const Modint& a, const Modint& b) { Modint res = a; res /= b; return res; }
    friend std::strong_ordering operator<=>(const Modint& a, const Modint& b) { return a.v <=> b.v; }
    friend bool operator==(const Modint& a, const Modint& b) { return a.v == b.v; }
    Modint operator^(int64_t p) {
        if(p < 0) return inv() ^ -p;
        Modint a = *this, res{1}; while(p > 0) {
            if(p & 1) res *= a;
            p >>= 1; if(p > 0) a *= a;
        } return res;
    }
};

template <class T, bool ONE = true>
struct BIT {
    int N; vector<T> bit;
    BIT(int N): N(N), bit(N + 1) {}

    T query(int i) {
        T res = 0;
        for(i += !ONE; i; i -= i & -i)
            res += bit[i];
        return res;
    }

    void update(int i, T val) {
        for(i += !ONE; i <= N; i += i & -i)
            bit[i] += val;
    }
};

template<class T, bool ONE = true>
class Segtree {
    int N; vector<T> st;

    template<typename V>
    void build(int node, int L, int R, const vector<V>& a) {
        if(L == R) return st[node] = static_cast<T>(a[L - ONE]), void();
        int M = L + R >> 1;
        build(node << 1, L, M, a);
        build(node << 1 | 1, M + 1, R, a);
        st[node] = T(st[node << 1], st[node << 1 | 1]);
    }

    void Update(int node, int L, int R, int pos, const T& val) {
        if(L == R) return st[node].upd(val);
        int M = L + R >> 1;
        pos <= M? Update(node << 1, L, M, pos, val)
                    : Update(node << 1 | 1, M + 1, R, pos, val);
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

    int Queryk(int node, int L, int R, typename T::V val) {
        if(L == R) return val <= st[node]? L : -1;
        int M = L + R >> 1;
        return val <= st[node << 1]?
                    Queryk(node << 1, L, M, val)
                        : Queryk(node << 1 | 1, M + 1, R, val - st[node << 1]);
    }

public:

    template<typename V>
    Segtree(const vector<V>& a): N(a.size()) {
        st.resize((1 << 31 - __builtin_clz(N << 1) + !!(N & N-1)) + 2);
        build(1, ONE, N - !ONE, a);
    }

    template<class... Args>
    Segtree(int n, Args&&... args): Segtree(vector<T>(n, T(forward<Args>(args)...))) {}

    void update(int pos, const T& val) { Update(1, ONE, N - !ONE, pos, val); }

    T query(int pos) { return Query(1, ONE, N - !ONE, pos, pos); }
    T query(int l, int r) { return l > r? T() : Query(1, ONE, N - !ONE, l, r); }
    int queryk(typename T::V val) { return Queryk(1, ONE, N - !ONE, val); }

};

struct Node {
    using V = Modint<1'000'000'000 + 7>;
    int last; V val;
    Node(int last = -1, V val = 0): last(last), val(val) {}
    Node(const Node& l, const Node& r) {
        last = max(l.last, r.last);
        if(l.last == last) val += l.val;
        if(r.last == last) val += r.val;
    }
    void upd(const Node& del) { *this = Node(*this, del); }
    operator V() const { return val; }
};

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    using mint = Modint<1'000'000'000 + 7>;

    int tests; cin >> tests;
    while(tests--) []() {
        int i, n; mint ans;
        cin >> n;
        vector<int> a(n);
        for(auto& x: a) cin >> x;

        auto b = a;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for(auto& x: a) x = R::lower_bound(b, x) - b.begin();
        int m = b.size();

        BIT<mint, 0> bit(m);
        vector<mint> cnt_left(n);
        for(i = 0; i < n; i++) {
            cnt_left[i] = bit.query(a[i] - 1) + 1;
            bit.update(a[i], cnt_left[i]);
        }

        Segtree<Node, 0> seg(m);
        bit = BIT<mint, 0>(m + 1);
        for(i = n - 1; ~i; i--) {
            auto cnt_right = bit.query(m) - bit.query(a[i]) + 1;
            bit.update(a[i], cnt_right);

            Node extra(Node(i, 1), seg.query(a[i] + 1, m - 1));
            seg.update(a[i], extra);

            ans += cnt_left[i] * (cnt_right - extra);
            auto x = cnt_left[i] * (cnt_right - extra);
        }

        cout << ans << '\n';
    }();

} // ~W