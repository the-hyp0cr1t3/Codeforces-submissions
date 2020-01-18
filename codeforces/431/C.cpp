#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define e "\n"
using namespace std;
#define Tp template<class T>
#define Tp2 template<class T1, class T2>
#define Tps template<class T, class... Ts>
#define Tps2 template<class T1, class T2, class... Ts>
#define ff first
#define ss second
#define rev(a) reverse(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins insert
#define pb push_back
#define sz(x) (int)(x).size()
#define MOD 1000000007  //1e9 + 7
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace maxmin {
    Tp T max (T&& a) { return a; }
    Tp T min (T&& a) { return a; }
    Tp T max (T&& a, T&& b) { return a>b?a:b; }
    Tp T min (T&& a, T&& b) { return a<b?a:b; }
    Tps T max (T&& a, Ts&&... ts) { T b = max(ts...); return a>b?a:b; }
    Tps T min (T&& a, Ts&&... ts) { T b = min(ts...); return a<b?a:b; }
    Tps T chmax(T&& a, Ts&&... ts) { a = max(a, ts...); return a; }
    Tps T chmin(T&& a, Ts&&... ts) { a = min(a, ts...); return a; }
}
struct num {
    static constexpr int mod = MOD;
    int v; 
    using ll = long long;
    static int inv(int a, int m) { a %= m; return a == 1 ? 1 : (int)(m - ll(inv(m, a)) * ll(m) / a); } 
    num() : v(0) {}
    num(ll v_) : v (int(v_ % mod)) { if (v < 0) v += mod; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const num& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, num& n) { ll v_; in >> v_; n = num(v_); return in; } 
    friend bool operator == (const num& a, const num& b) { return a.v == b.v; }
    friend bool operator != (const num& a, const num& b) { return a.v != b.v; }
    num inv() const { num res; res.v = inv(v, mod); return res; }
    num operator- () const { num res; res.v = v ? mod-v : 0; return res; }
    num operator+ () const { return num(*this); }
    num& operator ++ () { v ++; if (v == mod) v = 0; return *this; }
    num& operator -- () { if (v == 0) v = mod; v --; return *this; }
    num& operator += (const num& o) { v += o.v; if (v >= mod) v -= mod; return *this; }
    num& operator -= (const num& o) { v -= o.v; if (v < 0) v += mod; return *this; }
    num& operator *= (const num& o) { v = int(ll(v) * ll(o.v) % mod); return *this; }
    num& operator /= (const num& o) { return *this *= o.inv(); }
    friend num operator ++ (num& a, int) { num r = a; ++a; return r; }
    friend num operator -- (num& a, int) { num r = a; --a; return r; }
    friend num operator + (const num& a, const num& b) { return num(a) += b; }
    friend num operator - (const num& a, const num& b) { return num(a) -= b; }
    friend num operator * (const num& a, const num& b) { return num(a) *= b; }
    friend num operator / (const num& a, const num& b) { return num(a) /= b; }
    friend bool operator < (const num& a, const num& b) { return num(a).v < b.v; }
    friend bool operator <= (const num& a, const num& b) { return num(a).v <= b.v; }
    friend bool operator > (const num& a, const num& b) { return num(a).v > b.v; }
    friend bool operator >= (const num& a, const num& b) { return num(a).v >= b.v; }
};

namespace input { 
    Tp void re(T&& x) { cin >> x; }
    Tp2 void re(pair<T1,T2>& p) { re(p.ff); re(p.ss); }
    Tp void re(vector<T>& a) { for(int i = 0; i < sz(a); i++) re(a[i]); }
    Tp2 void rea(T1&& a, T2 t) { for(int i = 0; i < t; i++) re(a[i]); }
    Tp2 void rea1(T1&& a, T2 t) { for(int i = 1; i <= t; i++) re(a[i]); }
    Tps void re(T&& t, Ts&... ts) { re(t); re(ts...); }
}
namespace output {
    void pr(int x) { cout << x; }
    void pr(num x) { cout << x; }
    void pr(bool x) { cout << x; }
    void pr(long long x) { cout << x; }
    void pr(long long unsigned x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const char* x, size_t len) { cout << string(x, len); }
    void ps() { pr("\n"); }
    void pw() { pr(" "); }
    void pc() { pr("]\n"); }
    bool parse(const char* t) { if(t == e) return true; return false;}
    Tp void pr(const T&);
    Tp bool parse(T&& t) { return false;}
    Tp2 void psa(T1&& a, T2 t) { for(int i = 0; i < t; i++) pr(a[i]), pr(" "); ps(); }
    Tp2 void psa2(T1&& a, T2 t1, T2 t2) { for(int i = 0; i < t1; i++) {for(int j = 0; j < t2; j++) pr(a[i][j]), pr(" "); ps();} }
    Tp2 void pr(const pair<T1,T2>& x) { pr("{"); pr(x.ff); pr(", "); pr(x.ss); pr("}"); }
    Tp void pr(const T& x) { pr("{"); bool fst = 1; for (const auto& a: x) pr(!fst?", ":""), pr(a), fst = 0; pr("}"); }
    Tps void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
    Tps void ps(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) {if (!parse(t)) pr(" "); } ps(ts...); }
    Tp void pwv(const T& x) { for (const auto& a: x) pr(a), pw(); ps(); }
    Tps void pw(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(" "); pw(ts...); }
    Tps void pc(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); }
    namespace trace {
        #define tr(x...) pr("[",#x,"] = ["), pc(x);
        #define tra(x, y...) __f0(#x, x, y)
        #define tran(n, x) __fn(n, #x, x) // TO DO~ variadic multidimensional
        Tp2 void __f(const char* name, const T1& x, const T2& y){ pr("[",y,"] = "); ps(x); }
        Tps2 void __f(const char* name, const T1& x, const T2& y, const Ts&... rest){ const char *open = strchr(name, '['); pr("[",y,"]"); __f(open+1, x, rest...); }
        Tps2 void __f0(const char* name, const T1& x, const T2& y, const Ts&... rest){ const char *open = strchr(name, '['); pr(name, size_t(open-name)); __f(name, x, y, rest...); }
        Tp void __fn(int n, const char* name, const T& x) { for(int i = 0; i < n; i++) pr(name), __f(name, x[i], i); }
    }
}
using namespace maxmin;
using namespace input;
using namespace output;
using namespace output::trace;
using pii = pair<int, int>;
using ll = long long;
const int N = 2e5 + 5;
num dp[N][2];
int32_t main() {
    IOS;
    int n, k, d;
    num ans;
    re(n, k, d);
    for(int i = 1; i <= k; i++) 
        dp[i][i>=d] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < min(i, d); j++) {
            dp[i][0] += dp[i-j][0];
            dp[i][1] += dp[i-j][1];
        }
        for(int j = d; j <= min(i, k); j++) 
            dp[i][1] += dp[i-j][0] + dp[i-j][1];
    }
    ps(dp[n][1]);
    return 0;
}
//is a bruteforce possible?
//think greedier, make more assumptions
//stuck for more than 5 minutes? move on