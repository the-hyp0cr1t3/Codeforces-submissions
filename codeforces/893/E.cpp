/**
 🍪 the_hyp0cr1t3
 🍪 12.12.2020 21:38:02
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
const int INF = 2e9, MOD = 1e9+7;
using mint = Modint<MOD>;
const int N = 1e6 + 50;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; cin >> Q;

    array<int, N> spf; iota(all(spf), 0);
    for(int z = 4; z < N; z += 2) spf[z] = 2;
    for(int z = 3; z*z < N; z += 2)
        if(spf[z] == z) for(int y = z*z; y < N; y += z*2)
            if(spf[y] == y) spf[y] = z;
    
    vector<mint> fact, factinv, inv;
    inv = {0, 1}; fact = factinv = {1, 1};
    fact.resize(N); factinv.resize(N); inv.resize(N);
    for(int z = 2; z < N; z++) {
        inv[z] = inv[MOD % z] * (MOD - MOD / z);
        fact[z] = z * fact[z-1];
        factinv[z] = inv[z] * factinv[z-1];
    }
    
    auto nCr = [&](int n, int r) {
        return r < 0 or r > n? 0 : fact[n] * factinv[r] * factinv[n-r];
    };
    
    while(Q--) {
        int prod, n; cin >> prod >> n;
        mint ans = mint(2) ^ n-1;
        while(prod > 1) {
            int p = spf[prod], cnt = 0;
            while(spf[prod] == p) prod /= p, cnt++;
            ans *= nCr(n-1+cnt, cnt);
        } cout << ans << '\n';
    }
} // ~W 