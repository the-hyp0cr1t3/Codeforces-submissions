/**
 🍪 the_hyp0cr1t3
 🍪 29.09.2020 19:15:38
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

struct num {
    typedef decay<decltype(MOD)>::type T;
    T v; using ll = int64_t;
    static T inv(T a, T m) { a %= m; return a == 1 ? 1 : (T)(m - ll(inv(m, a)) * ll(m) / a); } 
    num() : v(0) {}
    num(ll v_) {
        v = (-MOD < v_ && v_ < MOD) ? T(v_) : T(v_ % MOD);
        if (v < 0) v += MOD;
    }
    explicit operator T() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const num& n) { return out << T(n); }
    friend std::istream& operator >> (std::istream& in, num& n) { ll v_; in >> v_; n = num(v_); return in; } 
    friend bool operator == (const num& a, const num& b) { return a.v == b.v; }
    friend bool operator != (const num& a, const num& b) { return a.v != b.v; }
    num inv() const { num res; res.v = inv(v, MOD); return res; }
    num operator- () const { num res; res.v = v ? MOD-v : 0; return res; }
    num operator+ () const { return num(*this); }
    num& operator ++ () { v ++; if (v == MOD) v = 0; return *this; }
    num& operator -- () { if (v == 0) v = MOD; v --; return *this; }
    num& operator += (const num& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    num& operator -= (const num& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    num& operator *= (const num& o) { v = T(ll(v) * ll(o.v) % MOD); return *this; }
    num& operator /= (const num& o) { return *this *= o.inv(); }
    friend num operator ++ (num& a, int) { num r = a; ++a; return r; }
    friend num operator -- (num& a, int) { num r = a; --a; return r; }
    friend num operator + (const num& a, const num& b) { return num(a) += b; }
    friend num operator - (const num& a, const num& b) { return num(a) -= b; }
    friend num operator * (const num& a, const num& b) { return num(a) *= b; }
    friend num operator / (const num& a, const num& b) { return num(a) /= b; }
    friend bool operator < (const num& a, const num& b) { return a.v < b.v; }
    friend bool operator <= (const num& a, const num& b) { return a.v <= b.v; }
    friend bool operator > (const num& a, const num& b) { return a.v > b.v; }
    friend bool operator >= (const num& a, const num& b) { return a.v >= b.v; }
};

const int N = 2e5 + 5;
num fact[N], factinv[N], inv[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, m, b;
    cin >> n >> m >> b;
    vector<pair<int, int>> blacks{{n, m}};
    blacks.reserve(b+1);
    for(i = 0; i < b; i++) {
        int x, y; cin >> x >> y;
        blacks.pb(x, y);
    } sort(all(blacks)), ++b;

    fact[0] = factinv[0] = 1;
    fact[1] = factinv[1] = inv[1] = 1;
    for(i = 2; i < N; i++) {
        fact[i] = fact[i-1] * num(i);
        inv[i] = num(-MOD/i) * inv[MOD%i];
        factinv[i] = factinv[i-1] * inv[i];
    }
    
    auto nCr = [&](int n, int r) {
        return r > n? num(0) : fact[n] * factinv[r] * factinv[n-r];
    };
    
    vector<num> ans(b);
    for(i = 0; i < b; i++) {
        auto [x, y] = blacks[i];
        ans[i] = nCr(x+y-2, x-1);
        for(j = 0; j < i; j++) {
            auto [px, py] = blacks[j];
            if(py <= y) ans[i] -= nCr(x-px+y-py, x-px) * ans[j];
        }
    } cout << ans.back();
}