#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
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
namespace input { 
    template<typename T> void re(T&& x) { cin >> x; }
    template<typename T1, typename T2> void re(pair<T1,T2>& p) { re(p.ff); re(p.ss); }
    template<typename T> void re(vector<T>& a) { for(int i = 0; i < sz(a); i++) re(a[i]); }
    template<typename T, typename Tsize> void rea(T&& a, Tsize t) { for(int i = 0; i < t; i++) re(a[i]); }
    template<typename T, typename... Ts> void re(T&& t, Ts&... ts) { re(t); re(ts...); }
}
namespace output {
    void pr(int x) { cout << x; }
    void pr(long long x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const char* x, size_t len) { cout << string(x, len); }
    void ps() { pr("\n"); }
    void pc() { pr("]\n"); }
    template<typename T, typename Tsize> void psa(T&& a, Tsize t) { for(int i = 0; i < t; i++) pr(a[i]), pr(" "); ps(); }
    template<typename T1, typename T2> void pr(const pair<T1,T2>& x) { pr("{"); pr(x.ff); pr(", "); pr(x.ss); pr("}"); }
    template<typename T> void pr(const T& x) { pr("{"); bool fst = 1; for (const auto& a: x) pr(!fst?", ":""), pr(a), fst = 0; pr("}"); }
    template<typename T, typename... Ts> void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
    template<typename T, typename... Ts> void ps(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); }
    template<typename T, typename... Ts> void pc(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); }
    namespace trace {
        #define tr(x...) pr("[",#x,"] = ["), pc(x);
        #define tra(x, y) __f(#x, x, y)
        template <typename T1, typename T2>
        void __f(const char* name, T1&& x, T2&& y){
            const char *open = strchr(name + 1, '['); 
            pr(name, size_t(open-name)); pr("[",y,"] = "); ps(x);
        }
    }
}
using namespace input;
using namespace output;
using namespace output::trace;
using pii = pair<int, int>;
using ll = long long;
const int N = 500 + 5;
int a[N][N], dp[N][N][2];
int32_t main() {
    IOS;
    int i, j, h, w, q;
    re(h, w);
    char c;
    auto cnt = [&] () {
        if (!a[i][j]) return 0;
        return a[i-1][j] +  a[i][j-1];
    };
    for(i = 1; i <= h; i++)
        for(j = 1; j <= w; j++)
            re(c), a[i][j] = c=='.'?1:0;

    for(i = 1; i <= h; i++) {
        for(j = 1; j <= w; j++) {
            dp[i][j][0] = dp[i][j-1][0] + dp[i-1][j][0] - dp[i-1][j-1][0] + (a[i][j] and a[i][j-1]);
            dp[i][j][1] = dp[i-1][j][1] + dp[i][j-1][1] - dp[i-1][j-1][1] + (a[i][j] and a[i-1][j]);
        }
    }
    re(q);
    while (q--) {
        int x1, y1, x2, y2, ans = 0;    
        re(x1, y1, x2, y2);
        ans += dp[x2][y2][0] - dp[x2][y1][0] - dp[x1-1][y2][0] + dp[x1-1][y1][0];
        ans += dp[x2][y2][1] - dp[x2][y1-1][1] - dp[x1][y2][1] + dp[x1][y1-1][1];
        ps(ans);
    }
    return 0;
}