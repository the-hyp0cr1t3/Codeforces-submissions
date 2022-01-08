/**
 🍪 the_hyp0cr1t3
 🍪 08.01.2022 19:33:50
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

    int i, n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) cin >> x;

    mint ans = 0;
    stack<int> mxstk, mnstk;
    vector<mint> pref(n + 1, 1);
    for(i = 1; i <= n; i++) {
        while(!mxstk.empty() and a[i - 1] >= a[mxstk.top() - 1]) {
            int j = mxstk.top(); mxstk.pop();
            ans -= (pref[j - 1] - (mxstk.empty()? 0 : pref[mxstk.top() - 1])) * a[j - 1];
        }
        ans += (pref[i - 1] - (mxstk.empty()? 0 : pref[mxstk.top() - 1])) * a[i - 1];
        pref[i] = pref[i - 1] + ans;
        mxstk.push(i);

        while(!mnstk.empty() and a[i - 1] <= a[mnstk.top() - 1]) {
            int j = mnstk.top(); mnstk.pop();
            ans += (pref[j - 1] - (mnstk.empty()? 0 : pref[mnstk.top() - 1])) * a[j - 1];
        }
        ans -= (pref[i - 1] - (mnstk.empty()? 0 : pref[mnstk.top() - 1])) * a[i - 1];
        pref[i] = pref[i - 1] + ans;
        mnstk.push(i);

    }

    cout << ans;
} // ~W