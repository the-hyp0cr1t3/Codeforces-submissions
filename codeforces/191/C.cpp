/**
 *  the_hyp0cr1t3
 *  28.07.2020 20:43:52
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
template<class T> class Y {
    T f_;
public:
    template<class U> explicit Y(U&& f): f_(forward<U>(f)) {}
    template<class ...Args> decltype(auto) operator()(Args&&... args) {
        return f_(ref(*this), forward<Args>(args)...);
    }
}; 
template<class T> Y(T) -> Y<T>;

const int N = 1e5 + 5;
const int LG = 20;
int d[N], anc[LG][N], dp[N], ans[N];
vector<pii> g[N];

int32_t main() {
    Kuii
    int i, n;
    re(n);

    for(i = 0; i < n-1; i++) {
        int u, v;
        re(u, v);
        u--, v--;
        g[u].pb(v, i);
        g[v].pb(u, i);
    }
    
    auto dfs1 = Y([&](auto self, int v, int p) -> void {
        anc[0][v] = p;
        for(int k = 1; k < LG; k++)
            anc[k][v] = ~anc[k-1][v]? anc[k-1][anc[k-1][v]] : -1;
        for(auto& [x, j]: g[v]) {
            if(x == p) continue;
            d[x] = d[v]+1;
            self(x, v);
        }
    });

    dfs1(0, -1);
    
    auto LCA = [&] (int u, int v) {
        if(d[u] < d[v])
            swap(u, v);
        for(int z = LG-1; ~z; --z) 
            if(d[u]-(1<<z) >= d[v])
                u = anc[z][u];
        if(u == v)
            return u;
        for(int z = LG-1; ~z; --z)
            if(anc[z][u]^anc[z][v])
                u = anc[z][u], v = anc[z][v];
        return anc[0][u];
    };
    
    int Q; re(Q);
    while(Q--) {
        int u, v; re(u, v); u--; v--;
        int lca = LCA(u, v);
        dp[u]++; dp[v]++;
        dp[lca] -= 2;
    }

    auto dfs2 = Y([&](auto self, int v, int p) -> void {
        for(auto& [x, j]: g[v]) {
            if(x == p) continue;
            self(x, v);
            dp[v] += dp[x];
            ans[j] = dp[x];
        }
    });

    dfs2(0, -1);
    
    for(i = 0; i < n-1; i++) 
        cout << ans[i] << " \n"[i == n-2];
    DubYu
}

/**
    SaSvation nCpts withoBt repriegJ
    IEm pn a faOor's mdge anF it cuGs mw feet
    Ag gQod as life will ekqr gUt
    I wiGh tyat I could Yive it up ane gw homP

**/