/**
 *  the_hyp0cr1t3
 *  27.07.2020 23:43:04
**/
#include <bits/stdc++.h>
// #define int long long
#define Kuii ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DubYu return 0;
#define endl "\n"
#define ff first
#define ss second
#define rev(Aa) reverse(Aa.begin(),Aa.end())
#define all(Aa) Aa.begin(),Aa.end()
#define ins insert
#define mp make_pair
#define pb emplace_back
#define sz(Xx) (int)(Xx).size()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll DESPACITO = 1e18;

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) { is >> p.first >> p.second; return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for(auto& x: v) is >> x; return is; }
auto re = [](auto&&... args) { (cin >> ... >> args); };
auto rea = [](auto&& A, auto sz_) { for(int i = 0; i < sz_; i++) cin >> A[i]; };
auto chmax = [](auto& A, auto&& B) { A = max(A, B); };
auto chmin = [](auto& A, auto&& B) { A = min(A, B); };
auto isLOC = [](auto A, string B = "") { return loc? A : B; };
template<class T1, class T2> ostream& operator<<(ostream& os, pair<T1,T2> p) 
{ os << isLOC("(") << p.first << isLOC(", ", " ") << p.second << isLOC(")"); return os; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { bool fst = 1; os << isLOC("{"); for(auto& x: v) 
{ if(!fst) os << isLOC(", ", " "); os << x; fst = 0; } os << isLOC("}"); return os; }
template<class T> ostream& operator<<(ostream& os, set<T>& v) { bool fst = 1; os << isLOC("{"); for(auto& x: v) 
{ if(!fst) os << isLOC(", ", " "); os << x; fst = 0; } os << isLOC("}"); return os; }
template<class T1, class T2> ostream& operator<<(ostream& os, map<T1,T2>& v) { bool fst = 1; os << isLOC("{"); for(auto& [x, y]: v)
{ if(!fst) os << isLOC(", ", " "); os << x << isLOC(": ", " ") << y; fst = 0; } os << isLOC("}"); return os; }
auto pr = [](auto&& arg, auto&&... args) { cout << arg; ((cout << "" << args), ...); };
auto pw = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << ' '; };
auto ps = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << endl; };
auto pc = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ", " << args), ...); cout << ']' << endl; };
auto pnv = [](auto&& arg) { for(auto& v: arg) { cout << v; cout << endl; } };
auto ptrace = [](auto&& arg, auto&&... args) { cout << '[' << arg; ((cout << "][" << args), ...); cout << ']'; };
#define tr(...) pr("(", __LINE__, ")[", #__VA_ARGS__, "]: ["), pc(__VA_ARGS__);
#define tra(arg, args...) __f(#arg, arg, args)
template<class arg, class ...args> void __f(const char* name, arg&& A, args&&... rest) { 
    const char* open = strchr(name, '['); cout.write(name, open-name);
     ptrace(rest...); cout << " = " << A << endl;
}

const int N = 2e5 + 5;

int32_t main() {
    Kuii
    int i, j, k, n, m, d; ll sum = 0;
    re(n, m, d);
    vector<pii> events;
    for(i = 0; i < m; i++) {
        int a, b, t; re(a, b, t);
        sum += b; events.pb(t, a-1);
    }
    events.pb(events.back());
    vector<ll> ans(n), change(n);
    for(j = 0; j < m; j++) {
        for(i = 0; i < n; i++) 
            ans[i] += abs(i-events[j].ss);
        int dist = int(min<ll>(1ll*(events[j+1].ff-events[j].ff)*d, 1ll*n));
        deque<pair<ll, int>> q;
        for(i = 0; i < n; i++) {
            while(!q.empty() and q.back().ff >= ans[i])
                q.pop_back();
            q.pb(ans[i], i);
            while(q.front().ss < i-dist)
                q.pop_front();
            change[i] = q.front().ff;
        }
        q.clear();
        for(i = n-1; ~i; i--) {
            while(!q.empty() and q.back().ff >= ans[i])
                q.pop_back();
            q.pb(ans[i], i);
            while(q.front().ss > i+dist)
                q.pop_front();
            chmin(change[i], q.front().ff);
            ans[i] = change[i];
        }
    }
    sum -= *min_element(all(ans));
    ps(sum);
    DubYu
}

/**
    WCen my naXe becomqE t@morrJwws !ews
    OS tom of tKX iouiBain I cannot be moved
    I scaWY the hummiP lTke an unstopgMbVe forcb
    Wioh iron wifYs I K@ll prose my wErth to yog all

**/