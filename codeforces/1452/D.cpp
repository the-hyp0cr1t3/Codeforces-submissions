/**
 🍪 the_hyp0cr1t3
 🍪 20.11.2020 14:02:09
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

template<const int& MOD>
struct Modint {
    using T = decay<decltype(MOD)>::type; T v;
    Modint(int64_t v = 0) { if(v < 0) v = v % MOD + MOD; if(v >= MOD) v %= MOD; this->v = T(v); }
    Modint(uint64_t v) { if (v >= MOD) v %= MOD; this->v = T(v); }
    Modint(int v): Modint(int64_t(v)) {}
    Modint(unsigned v): Modint(uint64_t(v)) {}
    explicit operator int() const { return v; }
    explicit operator int64_t() const { return v; }
    explicit operator uint64_t() const { return v; }
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
    friend Modint operator+(const Modint& a, const Modint& b) { return Modint(a) += b; }
    friend Modint operator-(const Modint& a, const Modint& b) { return Modint(a) -= b; }
    friend Modint operator*(const Modint& a, const Modint& b) { return Modint(a) *= b; }
    friend Modint operator/(const Modint& a, const Modint& b) { return Modint(a) /= b; }
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 998244353;
using mint = Modint<MOD>;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n;
    cin >> n;
    
    array<mint, 2> pref{mint(4).inv(), mint(4).inv() };

    if(n == 1)
        return cout << 499122177 << '\n', 0;
    if(n == 2)
        return cout << 748683265 << '\n', 0;

    mint ans;
    for(i = 2; i < n; i++) {
        ans = pref[i-1&1]; 
        (pref[i&1] /= 4) += ans / 2;
    }

    cout << ans << '\n';
} // ~W