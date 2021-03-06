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
    template<typename T, typename Tsize> void psa2(T&& a, Tsize t1, Tsize t2) { for(int i = 0; i < t1; i++) {for(int j = 0; j < t2; j++) pr(a[i][j]), pr(" "); ps();} }
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
const int N = 2e5 + 5;
int a[N], nxt[N], prv[N];
int32_t main() {
    IOS;
    int i, n, j;
    string s;
    re(n);
    rea(a, n);
    int cur = n-1;
    nxt[cur] = INF;
    for(i = n-2; i >= 0; i--) {
        if (a[i] >= a[i+1]) cur = i+1;
        nxt[i] = cur;
    }
    cur = 0;
    prv[cur] = INF;
    for(i = 1; i < n; i++) {
        if (a[i] >= a[i-1]) cur = i-1;
        prv[i] = cur;
    }
    int l = 0, r = n-1;
    cur = 0;
    while (l <= r) {
        if (a[l] < a[r]) {
            if (a[l] > cur) {
                s += 'L';
                cur = a[l];
                l++;
            }
            else if (a[r] > cur) {
                s += 'R';
                cur = a[r];
                r--;
            }
            else
                break;
        }
        else if (a[l] > a[r]) {
            if (a[r] > cur) {
                s += 'R';
                cur = a[r];
                r--;
            }
            else if (a[l] > cur) {
                s += 'L';
                cur = a[l];
                l++;
            }
            else
                break;
        }
        else {
            if (a[l] <= cur) break;
            if (nxt[l] - l > r - prv[r]) {
                s += 'L';
                cur = a[l];
                l++;
            }
            else {
                s += 'R';
                cur = a[r];
                r--;
            }
        }
    }
    ps(sz(s));
    ps(s);
    return 0;
}