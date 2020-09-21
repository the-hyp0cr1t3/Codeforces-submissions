/**
 🍪 the_hyp0cr1t3
 🍪 21.09.2020 17:35:14
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int64_t DESPACITO = 2e18;
const int INF = 2e9;

template<int MOD>
struct modnum {
    typedef int T;
    T v; using ll = int64_t;
    static T inv(T a, T m) { a %= m; return a == 1 ? 1 : (T)(m - ll(inv(m, a)) * ll(m) / a); } 
    modnum() : v(0) {}
    modnum(ll v_) {
        v = (-MOD < v_ && v_ < MOD) ? T(v_) : T(v_ % MOD);
        if (v < 0) v += MOD;
    }
    explicit operator T() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << T(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; } 
    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
    modnum inv() const { modnum res; res.v = inv(v, MOD); return res; }
    modnum operator- () const { modnum res; res.v = v ? MOD-v : 0; return res; }
    modnum operator+ () const { return modnum(*this); }
    modnum& operator ++ () { v ++; if (v == MOD) v = 0; return *this; }
    modnum& operator -- () { if (v == 0) v = MOD; v --; return *this; }
    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = T(ll(v) * ll(o.v) % MOD); return *this; }
    modnum& operator /= (const modnum& o) { return *this *= o.inv(); }
    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
    friend bool operator < (const modnum& a, const modnum& b) { return a.v < b.v; }
    friend bool operator <= (const modnum& a, const modnum& b) { return a.v <= b.v; }
    friend bool operator > (const modnum& a, const modnum& b) { return a.v > b.v; }
    friend bool operator >= (const modnum& a, const modnum& b) { return a.v >= b.v; }
};

const int N = 1e5 + 5;
using num = modnum<1000000007>;
using num1 = modnum<1000000006>;

template<typename T>
T expo(T A, int64_t B) {
    T res{1}; while(B) {
        if(B & 1) res = res * A;
        B >>= 1; A = A * A;
    } return res;
}

int32_t main() {
    aylmao
    int i, n, Q; string s;
    cin >> s >> Q;
    vector<string> query(Q+1);
    for(i = 0; i < Q; i++)
        cin >> query[i];
    
    vector<vector<num>> cache(10, vector<num>(Q+1));
    vector<vector<num1>> len(10, vector<num1>(Q+1));
    vector<vector<int>> vis(10, vector<int>(Q+1));
    for(i = 0; i < 10; i++)
        cache[i][Q] = i, vis[i][Q] = 1, len[i][Q] = 1;

    auto calc = Y([&](auto dp, int d, int q) -> num {
        assert(q <= Q);
        auto& ans = cache[d][q];
        auto& length = len[d][q];
        if(vis[d][q]++) return ans;
        if(query[q][0]-'0' == d) {
            for(int j = 0, k = sz(query[q]); j < k-3; j++) {
                ans += expo(num(10), length.v) * dp(query[q][k-1-j]-'0', q+1);
                length += len[query[q][k-1-j]-'0'][q+1];
            }
        } else ans = dp(d, q+1), length = len[d][q+1];
        return ans;
    });
    
    num ans; num1 curlen;
    for(reverse(all(s)), i = 0; i < sz(s); i++) {
        ans += expo(num(10), curlen.v) * calc(s[i]-'0', 0);
        curlen += len[s[i]-'0'][0];
    }

    cout << ans << '\n';
}