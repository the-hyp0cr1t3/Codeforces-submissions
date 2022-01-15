/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 17:57:28
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
    friend bool operator==(const Modint& a, const Modint& b) { return a.v == b.v; }
    friend bool operator!=(const Modint& a, const Modint& b) { return a.v != b.v; }
    friend bool operator<(const Modint& a, const Modint& b) { return a.v < b.v; }
    friend bool operator>(const Modint& a, const Modint& b) { return a.v > b.v; }
    friend bool operator<=(const Modint& a, const Modint& b) { return a.v <= b.v; }
    friend bool operator>=(const Modint& a, const Modint& b) { return a.v >= b.v; }
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
    using mint = Modint<998244353>;

    int i, j, k, m; string s;
    cin >> s >> m;
    array<int, 10> a{};
    a.fill(-1);
    for(i = 0; i < m; i++) {
        int x; cin >> x;
        a[x] = i;
    }

    int n = s.size();
    reverse(s.begin(), s.end());
    // dp[len][tight][msk] = sum of ints
    vector dp_sum(n + 1, vector<vector<mint>>(2, vector<mint>(1 << m)));
    vector dp_cnt(n + 1, vector<vector<mint>>(2, vector<mint>(1 << m)));
    dp_cnt[0][0][0] = dp_cnt[0][1][0] = 1;

    mint pow10 = 1, ans;
    for(i = 1; i <= n; i++, pow10 *= 10) {
        for(j = 0; j < 1 << m; j++) {
            for(k = 0; k < 10; k++) {
                int jj = j | (~a[k]? 1 << a[k] : 0);
                dp_cnt[i][0][jj] += dp_cnt[i - 1][0][j];
                dp_sum[i][0][jj] += dp_sum[i - 1][0][j] + dp_cnt[i - 1][0][j] * k * pow10;
                if(k <= s[i - 1] - '0') {
                    bool tight = k == s[i - 1] - '0';
                    dp_cnt[i][1][jj] += dp_cnt[i - 1][tight][j];
                    dp_sum[i][1][jj] += dp_sum[i - 1][tight][j] + dp_cnt[i - 1][tight][j] * k * pow10;
                }
            }
        }
        if(i < n and ~a[0])
            ans -= dp_sum[i][0][(1 << m) - 1 ^ (1 << a[0])];
    }

    ans += dp_sum[n][1][(1 << m) - 1];
    cout << ans;
} // ~W