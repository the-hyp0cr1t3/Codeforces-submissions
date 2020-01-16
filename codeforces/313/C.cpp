#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define e "\n"
using namespace std;
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
    template<typename T> T max (T&& a) { return a; }
    template<typename T> T min (T&& a) { return a; }
    template<typename T> T max (T&& a, T&& b) { return a>b?a:b; }
    template<typename T> T min (T&& a, T&& b) { return a<b?a:b; }
    template<typename T, typename... Ts> T max (T&& a, Ts&&... ts) { T b = max(ts...); return a>b?a:b; }
    template<typename T, typename... Ts> T min (T&& a, Ts&&... ts) { T b = min(ts...); return a>b?a:b; }
    template<typename T, typename... Ts> T chmax(T&& a, Ts&&... ts) { a = max(a, ts...); return a; }
    template<typename T, typename... Ts> T chmin(T&& a, Ts&&... ts) { a = min(a, ts...); return a; }
}
namespace input { 
    template<typename T> void re(T&& x) { cin >> x; }
    template<typename T1, typename T2> void re(pair<T1,T2>& p) { re(p.ff); re(p.ss); }
    template<typename T> void re(vector<T>& a) { for(int i = 0; i < sz(a); i++) re(a[i]); }
    template<typename T, typename Tsize> void rea(T&& a, Tsize t) { for(int i = 0; i < t; i++) re(a[i]); }
    template<typename T, typename Tsize> void rea1(T&& a, Tsize t) { for(int i = 1; i <= t; i++) re(a[i]); }
    template<typename T, typename... Ts> void re(T&& t, Ts&... ts) { re(t); re(ts...); }
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
    void ps() { pr("\n"); }
    void pw() { pr(" "); }
    void pc() { pr("]\n"); }
    bool parse(const char* t) { if(t == e) return true; return false;}
    template<typename T> bool parse(T&& t) { return false;}
    template<typename T, typename Tsize> void psa(T&& a, Tsize t) { for(int i = 0; i < t; i++) pr(a[i]), pr(" "); ps(); }
    template<typename T, typename Tsize> void psa2(T&& a, Tsize t1, Tsize t2) { for(int i = 0; i < t1; i++) {for(int j = 0; j < t2; j++) pr(a[i][j]), pr(" "); ps();} }
    template<typename T1, typename T2> void pr(const pair<T1,T2>& x) { pr("{"); pr(x.ff); pr(", "); pr(x.ss); pr("}"); }
    template<typename T> void pr(const T& x) { pr("{"); bool fst = 1; for (const auto& a: x) pr(!fst?", ":""), pr(a), fst = 0; pr("}"); }
    template<typename T, typename... Ts> void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
    template<typename T, typename... Ts> void ps(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) {if (!parse(t)) pr(" "); } ps(ts...); }
    template<typename T> void pwv(const T& x) { for (const auto& a: x) pr(a), pw(); ps(); }
    template<typename T, typename... Ts> void pw(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(" "); pw(ts...); }
    template<typename T, typename... Ts> void pc(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); }
    namespace trace {
        #define tr(x...) pr("[",#x,"] = ["), pc(x);
        #define tra(x, y...) __f0(#x, x, y)
        #define tran(n, x) __fn(n, #x, x) // TO DO~ variadic multidimensional
        template <typename T1, typename T2> void __f(const char* name, const T1& x, const T2& y){ pr("[",y,"] = "); ps(x); }
        template <typename T1, typename T2, typename... Ts> void __f(const char* name, const T1& x, const T2& y, const Ts&... rest){ const char *open = strchr(name, '['); pr("[",y,"]"); __f(open+1, x, rest...); }
        template <typename T1, typename T2, typename... Ts> void __f0(const char* name, const T1& x, const T2& y, const Ts&... rest){ const char *open = strchr(name, '['); pr(name, size_t(open-name)); __f(name, x, y, rest...); }
        template <typename T> void __fn(int n, const char* name, const T& x) { for(int i = 0; i < n; i++) pr(name), __f(name, x[i], i); }
    }
}
using namespace maxmin;
using namespace input;
using namespace output;
using namespace output::trace;
using pii = pair<int, int>;
#define int long long
const int N = 2e6 + 5;
int a[N];
int32_t main() {
    IOS;
    int i, n, cur = 1, p = 0, ans = 0;
    re(n); rea1(a, n);
    sort(a+1, a+1+n, greater<int>());
    i = n;
    while(i > 1) i/=4, p++;
    for(i = 0; i <= p; i++) {
        int q = (1<<i)*(1<<i);
        while (cur <= q)
            ans += (p+1-i)*a[cur++];
    }
    ps(ans);
    return 0;
}