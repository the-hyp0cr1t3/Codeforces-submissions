#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;
#define e "\n"
#define endl "\n"
#define Tp template<class T>
#define Tp2 template<class T1, class T2>
#define Tps template<class T, class... Ts>
#define Tps2 template<class T1, class T2, class... Ts>
#define ff first
#define ss second
#define rev(Aa) reverse(Aa.begin(),Aa.end())
#define all(Aa) Aa.begin(),Aa.end()
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins insert
#define mp make_pair
#define pb emplace_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define sz(Xx) (int)(Xx).size()
typedef long long ll;
typedef long double ld;
typedef double db;
using pii = pair<int, int>;
const int MOD = 1000000007;  //1e9 + 7
const int INF = 2000000000;  //2e9
const ll DESPACITO = 1000000000000000000;  //1e18
namespace minmax {
    Tp T max(T&& A) { return A; }
    Tp T min(T&& A) { return A; }
    Tp T max(T&& A, T&& B) { return A>B?A:B; }
    Tp T chmin2(T&& A, T&& B) { return A<B?A:B; }
    Tps T max(T&& A, Ts&&... ts) { T B = max(ts...); return A>B?A:B; }
    Tps T min(T&& A, Ts&&... ts) { T B = min(ts...); return A<B?A:B; }
    Tps T chmax(T&& A, Ts&&... ts) { A = max(A, ts...); return A; }
    Tps T chmin(T&& A, Ts&&... ts) { A = min(A, ts...); return A; }
    Tp2 void chmin2(T1&& A, T2&& Aa, T1&& B, T2&& Bb) { if(B < A) A = B, Aa = Bb; }
    Tp2 void chmax2(T1&& A, T2&& Aa, T1&& B, T2&& Bb) { if(B > A) A = B, Aa = Bb; }
}
namespace input { 
    Tp void re(T&& Xx) { cin >> Xx; }
    Tp2 void re(pair<T1,T2>& Pp) { re(Pp.first); re(Pp.second); }
    Tp void re(vector<T>& Aa) { for(int i = 0; i < sz(Aa); i++) re(Aa[i]); }
    Tp2 void rea(T1&& Aa, T2 t) { for(int i = 0; i < t; i++) re(Aa[i]); }
    Tps2 void rea(T1&& Aa, T2 t, Ts&&... ts) { rea(Aa, t); rea(ts...); }
    Tp2 void rea1(T1&& Aa, T2 t) { for(int i = 1; i <= t; i++) re(Aa[i]); }
    Tps2 void rea1(T1&& Aa, T2 t, Ts&... ts) { rea1(Aa, t); rea1(ts...); }
    Tps void re(T&& t, Ts&... ts) { re(t); re(ts...); }
}
namespace output {
    void pr(int32_t Xx) { cout << Xx; }
    // void pr(num Xx) { cout << Xx; }
    void pr(bool Xx) { cout << Xx; }
    void pr(long long Xx) { cout << Xx; }
    void pr(long long unsigned Xx) { cout << Xx; }
    void pr(double Xx) { cout << Xx; }
    void pr(char Xx) { cout << Xx; }
    void pr(const string& Xx) { cout << Xx; }
    void pr(const char* Xx) { cout << Xx; }
    void pr(const char* Xx, size_t len) { cout << string(Xx, len); }
    void ps() { cout << endl; }
    void pn() { /*do nothing*/ }
    void pw() { pr(" "); }
    void pc() { pr("]"); ps(); }
    Tp2 void pr(const pair<T1,T2>& Xx) { pr(Xx.first); pw(); pr(Xx.second);}
    Tp void pr(const T&);
    bool parse(const char* t) { if(t == e) return true; return false;}
    Tp bool parse(T&& t) { return false;}
    Tp2 bool parsepair(const pair<T1,T2>& Xx) { return true; }
    Tp bool parsepair(T&& t) { return false;}
    Tp2 void psa(T1&& Aa, T2 t) { for(int i = 0; i < t; i++) pr(Aa[i]), pw(); ps(); }
    Tp2 void pna(T1&& Aa, T2 t) { for(int i = 0; i < t; i++) pr(Aa[i]), ps(); }
    Tp2 void psa2(T1&& Aa, T2 t1, T2 t2) { for(int i = 0; i < t1; i++) {for(int j = 0; j < t2; j++) pr(Aa[i][j]), pw(); ps();} }
    Tp void pr(const T& Xx) { if(!sz(Xx)) return; bool fst = 1; bool op = 0; if (parsepair(*Xx.begin())) op = 1; for (const auto& Aa: Xx) {if(!fst) pw(); if(op) pr("{"); pr(Aa), fst = 0; if(op) pr("}"); } }
    Tps void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
    Tps void ps(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) {if (!parse(t)) pw(); } ps(ts...); }
    Tp void pn(const T& t) { for (const auto& Aa: t) ps(Aa); }
    Tps void pw(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pw(); pw(ts...); }
    Tps void pc(const T& t, const Ts&... ts) { bool op = 0; if (parsepair(t)) op = 1; if(op) pr("{"); pr(t); if(op) pr("}"); if (sizeof...(ts)) pr(", "); pc(ts...); }
    namespace trace {
        #define tr(Xx...) pr("[",#Xx,"] = ["), pc(Xx);
        #define tra(Xx, y...) __f0(#Xx, Xx, y)
        #define tran(Xx, n) __fn(n, #Xx, Xx) // TO DO~ variadic multidimensional
        Tp2 void __f(const char* name, const T1& Xx, const T2& y){ pr("[",y,"] = "); ps(Xx); }
        Tps2 void __f(const char* name, const T1& Xx, const T2& y, const Ts&... rest){ const char *open = strchr(name, '['); pr("[",y,"]"); __f(open+1, Xx, rest...); }
        Tps2 void __f0(const char* name, const T1& Xx, const T2& y, const Ts&... rest){ const char *open = strchr(name, '['); pr(name, size_t(open-name)); __f(name, Xx, y, rest...); }
        Tp void __fn(int n, const char* name, const T& Xx) { for(int i = 0; i < n; i++) pr(name), __f(name, Xx[i], i); }
    }
}
const int NN = 1e5 + 5;
namespace DSU {
    int nn, par[NN], size_[NN];
    void build (int Q) {
        nn = Q;
        for(int i = 0; i < nn; i++) {
            par[i] = i;
            size_[i] = 1;
        }
    }
    int getpar(int x) {
        int pp = x;
        while(par[pp] != pp)
            pp = par[pp];
        while(par[x] != x) {
            int z = par[x];
            par[x] = pp;
            x = z;
        }
        return pp;
    }
    bool merge(int x, int y) {
        x = getpar(x);
        y = getpar(y);
        if (x == y) return false;
        if (size_[x] < size_[y]) swap(x, y);
        par[y] = x, size_[x] += size_[y];
        return true;
    }
}
using namespace DSU;
using namespace minmax;
using namespace input;
using namespace output;
using namespace output::trace;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3e5 + 5;
const int LG = 20;
int n, m, k, Q, d[N], p[N];
int anc[LG][N], best[LG][N];
vector<pii> g[N], tree[N];
vector<pair<int, pii>> oldedges, edges;

void makeG() {
    for(int i = 0; i < m; i++) {
        int u, v, w;
        re(u, v, w);
        u--, v--;
        oldedges.pb(w, mp(u, v));
        g[u].pb(v, w);
        g[v].pb(u, w);
    }
}

void dijkstra() {
    int i;
    set<pii> q;
    for(i = k; i < n; i++) 
        d[i] = DESPACITO, p[i] = -1;
    for(i = 0; i < k; i++) 
        d[i] = 0, q.ins({0, i}), p[i] = i;
    while(!q.empty()) {
        auto [y, v] = *q.begin();
        q.erase(q.begin());
        for(auto& [to, w]: g[v]) {
            if(d[to] > d[v] + w) {
                q.erase({d[to], to});
                d[to] = d[v] + w;
                q.ins({d[to], to});
                p[to] = v;
            }
        }
    }
}

void dfs(int v, int par) {
    anc[0][v] = par;
    for(int kk = 1; kk < LG; kk++) {
        anc[kk][v] = ~anc[kk-1][v]? anc[kk-1][anc[kk-1][v]] : -1;
        best[kk][v] = ~anc[kk-1][v]? max(best[kk-1][v], best[kk-1][anc[kk-1][v]]) : -1;
    }
    for (auto [x, w]: tree[v]) 
        if(x^par)
            d[x] = d[v]+1, best[0][x] = w, dfs(x, v);
}

int LCA(int u, int v) {
    if(d[u] < d[v])
        swap(u, v);
    for(int i = LG-1; ~i; --i) 
        if(d[u]-(1<<i) >= d[v])
            u = anc[i][u];
    if(u == v)
        return u;
    for(int i = LG-1; ~i; --i)
        if(anc[i][u]^anc[i][v])
            u = anc[i][u], v = anc[i][v];
    return anc[0][u];
}

int getpath(int v, int lca) {
    int diff = d[v] - d[lca], res = -1;
    for(int i = LG-1; ~i; i--)
        if(diff & (1<<i)) chmax(res, best[i][v]), v = anc[i][v];
    return res;
}

int32_t main() {
    IOS;
    int i;
    re(n, m, k, Q);
    makeG();
    dijkstra();
    for(auto& [w, ed]: oldedges)
        if(p[ed.ff] != p[ed.ss]) 
            edges.pb(w + d[ed.ff] + d[ed.ss], mp(p[ed.ff], p[ed.ss]));
    sort(all(edges));
    build(n);
    for(auto& [w, ed]: edges) {
        if(merge(ed.ff, ed.ss)) {
            tree[ed.ss].pb(ed.ff, w);
            tree[ed.ff].pb(ed.ss, w);
        }
    }
    for(i = 0; i < n; i++) 
        d[i] = 0;
    memset(best, -1, sizeof(best));
    dfs(0, -1);
    for(i = 0; i < Q; i++) {
        int u, v; re(u, v);
        --u; --v;
        int lca = LCA(u, v);
        ps(max(getpath(u, lca), getpath(v, lca)));
    }
    return 0;
}