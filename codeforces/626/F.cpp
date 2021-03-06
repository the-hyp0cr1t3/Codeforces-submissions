/**
 🍪 the_hyp0cr1t3
 🍪 30.09.2020 12:38:56
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

const int N = 200 + 5;
const int M = 1000 + 5;
int a[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, K, j, k;
    cin >> n >> K; K++;
    for(i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);

    // dp[no of open intervals (grps)][imbalance so far] = ways
    array<array<num, M>, N> dp;
    dp[0][0] = 1;
    dp[1][0] = 1;

    for(i = 1; i < n; i++) {
        // auto ndp = dp;
        array<array<num, M>, N> ndp;
        for(j = 0; j <= i; j++) {
            int increase = j * (a[i] - a[i-1]);
            for(k = 0; k + increase < K; k++) {
                // add a_i to a new grp and immediately close it
                ndp[j][k + increase] += dp[j][k];
                // add a_i to a new grp but dont close it
                ndp[j+1][k + increase] += dp[j][k];
                // add a_i to an existing grp and close it
                if(j > 0) ndp[j-1][k + increase] += dp[j][k] * j;
                // add a_i to an existing grp but dont close it
                if(j > 0) ndp[j][k + increase] += dp[j][k] * j;
            }
        }
        dp = ndp;
    }

    cout << std::accumulate(all(dp[0]), num(0)) << '\n';
}