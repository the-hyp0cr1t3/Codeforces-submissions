/**
 🍪 the_hyp0cr1t3
 🍪 11.12.2021 17:49:15
**/
#ifdef W
    #include <k_II.h>
    #undef e
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

constexpr int MOD = 998244353;
using mint = Modint<MOD>;

namespace NTT {
    const int FFT_CUTOFF = 150;
    vector<mint> roots = {0, 1};
    vector<int> bit_order;
    int max_size = 1;       // MOD = c∙2^k + 1, maxsize = 2^k
    mint root = 2;          // n must not exceed maxsize

    auto find_root = []() {
        int order = MOD-1;
        while(~order & 1) order >>= 1, max_size <<= 1;
        while((root ^ max_size) != 1 or (root ^ max_size/2) == 1)
            root++;
        return 'W';
    }();

    void prepare_roots(int n) {
        if(roots.size() >= n) return;
        int len = __builtin_ctz(roots.size());
        roots.resize(n);
        while(n > 1 << len) {
            mint z = root ^ max_size >> len + 1;
            for(int i = 1 << len-1; i < 1 << len; i++) {
                roots[i << 1] = roots[i];
                roots[i << 1 | 1] = roots[i] * z;
            } len++;
        }
    }

    void reorder_bits(int n, vector<mint>& a) {
        if(bit_order.size() != n) {
            bit_order.assign(n, 0);
            int len = __builtin_ctz(n);
            for(int i = 0; i < n; i++)
                bit_order[i] = (bit_order[i >> 1] >> 1) + ((i & 1) << len-1);
        }
        for(int i = 0; i < n; i++)
            if(i < bit_order[i]) swap(a[i], a[bit_order[i]]);
    }

    void fft(int n, vector<mint>& a) {
        assert(n <= max_size);
        prepare_roots(n); reorder_bits(n, a);
        for(int len = 1; len < n; len <<= 1)
            for(int i = 0; i < n; i += len << 1)
                for(int j = 0; j < len; j++) {
                    const mint& even = a[i + j];
                    mint odd = a[i + len + j] * roots[len + j];
                    a[i + len + j] = even - odd; a[i + j] = even + odd;
                }
    }

    template<typename T>
    vector<mint> multiply(const vector<T>& a, const vector<T>& b, bool trim = false) {
        int n = a.size(), m = b.size();
        if(n == 0 or m == 0)
            return vector<mint>{0};

        if(min(n, m) < FFT_CUTOFF) {
            vector<mint> res(n + m - 1);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    res[i + j] += mint(a[i]) * mint(b[j]);

            if(trim) {
                while(!res.empty() && res.back() == 0)
                    res.pop_back();
            }

            return res;
        }

        int N = [](int x) { while(x & x-1) x = (x | x-1) + 1; return x; }(n + m - 1);
        vector<mint> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        fa.resize(N); fb.resize(N);

        bool equal = fa == fb;

        fft(N, fa);
        if(equal) fb = fa;
        else fft(N, fb);

        mint inv_N = mint(N) ^ -1;
        for(int i = 0; i < N; i++)
            fa[i] *= fb[i] * inv_N;
        reverse(fa.begin() + 1, fa.end());

        fft(N, fa);

        fa.resize(n + m - 1);
        if(trim) {
            while(!fa.empty() && fa.back() == 0)
                fa.pop_back();
        }

        return fa;
    }

    template<typename T>
    vector<mint> expo(const vector<T>& a, int e, bool trim = false) {
        int n = a.size();
        int N = [](int x) { while(x & x-1) x = (x | x-1) + 1; return x; }((n-1) * e + 1);
        vector<mint> fa(a.begin(), a.end()); fa.resize(N);

        fft(N, fa);

        mint inv_N = mint(N) ^ -1;
        for(int i = 0; i < N; i++)
            fa[i] = (fa[i] ^ e) * inv_N;
        reverse(fa.begin() + 1, fa.end());

        fft(N, fa);
        fa.resize((n-1) * e + 1);

        if(trim) {
            while(!fa.empty() && fa.back() == 0)
                fa.pop_back();
        }

        return fa;
    }

} // namespace NTT

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int i, n;
    cin >> n;

    auto can = [](string x, string y) {
        return (y[0] == '?' or y[0] == x[0]) and (y[1] == '?' or y[1] == x[1]);
    };

    mint all = 1, onlywb = 1, onlybw = 1;
    vector<vector<mint>> poly;
    for(i = 0; i < n; i++) {
        string s; cin >> s;
        poly.emplace_back(vector<mint>{ can("BB", s), can("WB", s) + can("BW", s), can("WW", s) });
        all *= can("WB", s) + can("BW", s);
        onlywb *= can("WB", s);
        onlybw *= can("BW", s);
    }

    auto p = Y([&](auto self, int l, int r) -> vector<mint> {
        if(r - l == 1) return poly[l];
        int mid = l + r >> 1;
        return NTT::multiply(self(l, mid), self(mid, r));
    })(0, n);

    mint ans = p[p.size() / 2] - (all - onlywb - onlybw);

    cout << ans;
} // ~W