/**
 🍪 the_hyp0cr1t3
 🍪 09.11.2020 19:49:27
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

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

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
const int N = 2e5 + 5;
const int M = 12;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k, mx;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    } cin >> k >> mx;
    mx = min(mx, n);
    
    vector<array<array<mint, 3>, M>> dp(n);
    Y([&](auto self, int v, int p) -> void {
        dp[v] = {};
        dp[v][0][0] = k-1;
        dp[v][0][2] = m-k;
        dp[v][1][1] = 1;
        for(auto& x: g[v]) {
            if(x == p) continue;
            self(x, v);
            array<array<mint, 3>, M> newdp{};
            for(int i = 0; i <= mx; i++) {
                for(int j = 0; j+i <= mx; j++) {
                    newdp[j+i][0] += dp[v][j][0] * (dp[x][i][0] + dp[x][i][1] + dp[x][i][2]);
                    newdp[j+i+1][1] += dp[v][j+1][1] * dp[x][i][0];
                    newdp[j+i][2] += dp[v][j][2] * (dp[x][i][0] + dp[x][i][2]);
                }
            } dp[v] = newdp;
        }
    })(0, -1);
    
    mint ans;
    for(int i = 0; i <= mx; i++)
        ans += dp[0][i][0] + dp[0][i][1] + dp[0][i][2];
    cout << ans << '\n';
} // ~W