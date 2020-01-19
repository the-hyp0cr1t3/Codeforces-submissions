#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define e "\n"
#define endl "\n"
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
    //void pr(num x) { cout << x; }
    void pr(bool x) { cout << x; }
    void pr(long long x) { cout << x; }
    void pr(long long unsigned x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const char* x, size_t len) { cout << string(x, len); }
    void ps() { cout << endl; }
    void pw() { pr(" "); }
    void pc() { pr("]"); ps(); }
    bool parse(const char* t) { if(t == e) return true; return false;}
    Tp void pr(const T&);
    Tp bool parse(T&& t) { return false;}
    Tp2 void psa(T1&& a, T2 t) { for(int i = 0; i < t; i++) pr(a[i]), pw(); ps(); }
    Tp2 void psa2(T1&& a, T2 t1, T2 t2) { for(int i = 0; i < t1; i++) {for(int j = 0; j < t2; j++) pr(a[i][j]), pw(); ps();} }
    Tp2 void pr(const pair<T1,T2>& x) { pr("{"); pr(x.ff); pr(", "); pr(x.ss); pr("}"); }
    Tp void pr(const T& x) { bool fst = 1; for (const auto& a: x) pr(!fst?" ":""), pr(a), fst = 0; }
    Tps void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
    Tps void ps(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) {if (!parse(t)) pw(); } ps(ts...); }
    Tps void pw(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pw(); pw(ts...); }
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
#define int long long
using pii = pair<int, int>;
const int N = 2e16;
pii node[65];
int32_t main() {
    IOS;
    int i, j, x0, y0, ax, ay, bx, by, xs, ys, T;
    re(x0, y0, ax, ay, bx, by, xs, ys, T);
    int x = x0, y = y0, cnt = 0, ans = 0;
    while(x <= N and y <= N) {
        node[cnt++] = {x, y};
        x = ax*x + bx; y = ay*y + by;
    }
    for(i = 0; i < cnt; i++) {
        int t = T; t -= abs(xs-node[i].ff) + abs(ys-node[i].ss);
        if (t < 0) continue; int res = 1;
        for(j = i+1; j < cnt; j++) {
            t -= node[j].ff-node[j-1].ff+node[j].ss-node[j-1].ss;
            if (t < 0) break;
            res++;
        }
        t = T; t -= abs(xs-node[i].ff) + abs(ys-node[i].ss);
        chmax(ans, res); res = 1;
        for(j = i-1; j >= 0; j--) {
            t -= node[j+1].ff-node[j].ff+node[j+1].ss-node[j].ss;
            if (t < 0) break;
            res++;
        }
        chmax(ans, res);
    }
    ps(ans);
    return 0;
}