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
int n, dp[N], ans[N];
vector<pii> g[N];

int32_t main() {
    Kuii
    int i, j, k;
    re(n);

    for(i = 0; i < n-1; i++) {
        int u, v;
        re(u, v);
        u--, v--;
        g[u].pb(v, i);
        g[v].pb(u, i);
    }   
    
    int len = 2*n-1;
    vector<int> log2(len+1, -1);
    for(i = 1; i <= len; i++) 
        log2[i] = log2[i/2] + 1;
    int b = max(1, log2[len]/2);
    int cntb = (len+b-1)/b;
    vector<int> tin(n), d(n), tree, bmask(cntb);
    vector<vector<vector<int>>> best(1<<b-1);
    vector<vector<int>> sparse(log2[cntb]+1, vector<int>(cntb));
    tree.reserve(len);
    
    Y([&](auto dfs, int v, int p) -> void {
        tin[v] = sz(tree);
        tree.pb(v);
        for(auto [x, z]: g[v]) { 
            if(x == p) continue;
            d[x] = d[v] + 1;
            dfs(x, v);
            tree.pb(v);
        }    
    })(0, -1);
    
    auto lower = [&](int p, int q) {
        return d[tree[p]] < d[tree[q]]? p : q;
    };

    for(i = 0; i < len; i++) {
        int curb = i/b; j = i%b;
        if(!j or lower(sparse[0][curb], i) == i)
            sparse[0][curb] = i;
        if(j and lower(i-1, i) == i-1)
            bmask[curb] |= 1<<j-1;
    }

    for(k = 1; k <= log2[cntb]; k++) {
        for(i = 0; i < cntb; i++) {
            j = i + (1<<k-1);
            sparse[k][i] = sparse[k-1][i];
            if(j < cntb)
                sparse[k][i] = lower(sparse[k-1][i], sparse[k-1][j]);
        }
    }

    for(int curb = 0; curb < cntb; curb++) {
        int mask = bmask[curb];
        if(sz(best[mask])) continue;
        best[mask].resize(b, vector<int>(b));
        for(i = 0; i < b; i++) {
            best[mask][i][i] = i;
            for(j = i+1; j < b; j++) {
                if(b*curb+j >= len) break;
                best[mask][i][j] = lower(b*curb+best[mask][i][j-1], b*curb+j);
                best[mask][i][j] -= b*curb;
            }
        }
    }

    auto geti = [&](int curb, int l, int r) {
        return best[bmask[curb]][l][r] + b*curb;
    };

    auto LCA = [&](int u, int v) {
        u = tin[u];
        v = tin[v];
        if(u > v) swap(u, v);
        int bu = u/b, bv = v/b;
        if(bu == bv)
            return tree[geti(bu, u%b, v%b)];
        int res = lower(geti(bu, u%b, b-1), geti(bv, 0, v%b));
        if(bv-bu > 1) {
            int z = log2[bv-bu-1];
            res = lower(res, lower(sparse[z][bu+1], sparse[z][bv-(1<<z)]));
        }
        return tree[res];
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