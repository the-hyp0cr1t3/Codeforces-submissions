/**
 🍪 the_hyp0cr1t3
 🍪 08.12.2021 01:01:05
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

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int N = 500 + 5;
    const int MOD = 998244353;
    using mint = Modint<MOD>;

    static vector<mint> fact{1, 1}, factinv{1, 1}, inv{0, 1};
    [](int N) {
        fact.reserve(N); factinv.reserve(N); inv.reserve(N);
        for(int z = fact.size(); z < N; z++) {
            inv.push_back(inv[MOD % z] * (MOD - MOD / z));
            fact.push_back(z * fact[z-1]);
            factinv.push_back(inv[z] * factinv[z-1]);
        }
    }(N);

    auto nCr = [](int n, int r) {
        return r < 0 or r > n? 0 : fact[n] * factinv[r] * factinv[n-r];
    };

    int i, j, k, n, x;
    cin >> n >> x;

    vector<vector<mint>> dp(n + 1, vector<mint>(x + 1));
    dp[n][0] = 1;

    for(i = n; i > 1; i--) {
        for(j = 0; j <= i; j++) {
            for(k = 0; k <= x; k++) {
                int kk = min(x, k + i - 1);
                dp[i - j][kk] += dp[i][k] * nCr(i, j) * (mint(kk - k) ^ j);
            }
        }
    }

    cout << accumulate(dp[0].begin(), dp[0].end(), mint());
} // ~W