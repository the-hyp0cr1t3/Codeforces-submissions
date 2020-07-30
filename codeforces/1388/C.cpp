/**
 *  the_hyp0cr1t3
 *  30.07.2020 20:22:54
**/
#include <bits/stdc++.h>
#define int long long
#define k_II ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
template<class T> class Y {
    T f_;
public:
    template<class U> explicit Y(U&& f): f_(forward<U>(f)) {}
    template<class ...Args> decltype(auto) operator()(Args&&... args) {
        return f_(ref(*this), forward<Args>(args)...);
    }
}; 
template<class T> Y(T) -> Y<T>;

const int N = 2e5 + 5;
int p[N], h[N];

int solve () {
    int i, n, m;
    re(n, m); rea(p, n); rea(h, n);
    
    vector<int> sub(n);
    vector<vector<int>> g(n);
        
    for(i = 0; i < n-1; i++) {
        int u, v;
        re(u, v);
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    bool bad = 0;
    if(n == 1)
        return ps(abs(h[0]) <= p[0] and (h[0]&1) == (p[0]&1)?"Yes":"No"), 0;

    auto dfs = Y([&](auto self, int v, int par) -> int {
        sub[v] += p[v];
        if(sz(g[v]) == 1 and v) {
            if(abs(h[v]) > p[v] or (h[v]&1) != (p[v]&1)) 
                bad = 1;
            return h[v];
        }
        int res = 0;
        for(auto x: g[v]) { 
            if(x == par) continue; 
            res += self(x, v);
            sub[v] += sub[x];
        }
        if(sub[v] < h[v] or res - p[v] > h[v])
            bad = 1;
        else if((((res&1)+(p[v]&1))&1) != (h[v]&1))
            bad = 1;
        return h[v];
    });

    dfs(0, -1);
    
    ps(bad?"No":"Yes");
    return 0;
}

int32_t main() {
    k_II
    int Q;
    for(cin >> Q; Q; Q--)
        solve();
    DubYu
}

/**
    MomentH lost WParcving foo a dr!am tVjt's reaM
    From my hemrt I'd giQe io all ,waM ju^t to knYw
    HoZdiQg BiAh eaery answer sarle!.
    The path is hollo^edX bmmortazi.y we s!Bk.
    Ligh. sbre^mxng fyom belRwa this ,ife ls reborn.

**/