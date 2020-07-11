/**
 *  the_hyp0cr1t3
 *  11.07.2020 18:09:10
**/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
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

template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) { is >> p.first >> p.second; return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for(auto& x: v) is >> x; return is; }
auto re = [](auto&&... args) { (cin >> ... >> args); };
auto rea = [](auto&& A, auto sz_) { for(int i = 0; i < sz_; i++) cin >> A[i]; };
auto chmax = [](auto& A, auto&& B) { A = max(A, B); };
auto chmin = [](auto& A, auto&& B) { A = min(A, B); };
char delim = ' ';
template<class T1, class T2> ostream& operator<<(ostream& os, pair<T1,T2>& p) 
{ os << p.first << ' ' << p.second; return os; }
template<class T> ostream& operator<<(ostream& os, set<T>& v) { bool fst = 1; for(auto& x: v) 
{ if(!fst) os << delim; os << x; fst = 0; } return os; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { bool fst = 1; for(auto& x: v) 
{ if(!fst) os << delim; os << x; fst = 0; } return os; }
template<class T1, class T2> ostream& operator<<(ostream& os, map<T1,T2>& v) { 
bool fst = 1; for(auto& x: v) { if(!fst) os << delim; os << '{' << x << '}'; fst = 0; } return os; }
auto pr = [](auto&& arg, auto&&... args) { cout << arg; ((cout << "" << args), ...); };
auto pw = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << ' '; };
auto ps = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << endl; };
auto pc = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ", " << args), ...); cout << ']' << endl; };
auto pnv = [](auto&& arg) { for(auto& v: arg) { cout << v; cout << endl; } };
auto pn = [](auto&& arg, auto&&... args) { delim = '\n'; cout << arg; ((cout << endl << args), ...); cout << endl; delim = ' '; };
auto ptrace = [](auto&& arg, auto&&... args) { cout << '[' << arg; ((cout << "][" << args), ...); cout << ']'; };
#define tr(args...) pr('[', #args, "] = ["), pc(args);
#define tra(arg, args...) __f(#arg, arg, args)
template<class arg, class ...args> void __f(const char* name, arg&& A, args&&... rest) { 
    const char* open = strchr(name, '['); cout.write(name, open-name); 
    ptrace(rest...); cout << " = " << A << endl;
}

const int N = 2e5 + 5;
int a[N];
struct edge_t {
    int u, v, w;
    edge_t(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
    bool operator<(const edge_t& other) { return w < other.w; }
};
ostream& operator<<(ostream& os, edge_t& e) { os << e.u << ' ' << e.v << ' ' << e.w; return os; }

int32_t main() {
    IOS;
    int i, j, cure = 0, n, m, left, ans = 0;
    re(n, m); rea(a, n);
    vector<int> par(n), sz_(n, 1), nodes(n);
    iota(all(par), 0); iota(all(nodes), 0);
    vector<edge_t> edges;
    for(i = 0; i < m; i++) {
        int u, v, w;
        re(u, v, w);
        u--, v--;
        edges.pb(u, v, w);
    }
    sort(all(edges));
    sort(all(nodes), [](const auto& A, const auto& B) { 
        return a[A] < a[B]; 
    });
    left = n-1;
    
    auto getpar = [&] (int x) {
        int pp = x;
        while(par[pp] != pp)
            pp = par[pp];
        while(par[x] != x) {
            int z = par[x];
            par[x] = pp;
            x = z;
        }
        return pp;        
    };
    
    auto merge = [&] (int x, int y) {
        x = getpar(x);
        y = getpar(y);
        if (x == y) return false;
        if (sz_[x] < sz_[y]) swap(x, y);
        par[y] = x, sz_[x] += sz_[y];
        return true;
    };

    auto addedge = [&] (edge_t e) {
        if(merge(e.u, e.v))
            ans += e.w, left--;
    };
     
    for(i = 0; i < n and left; i++) {
        for(j = i+1; j < n and left; j++) {
            auto e = edge_t(nodes[i], nodes[j], a[nodes[i]] + a[nodes[j]]);
            while(left and cure < m and edges[cure].w < e.w)
                addedge(edges[cure++]);
            if(left) addedge(e);
        }
    }
    
    ps(ans);
    return 0;
}

/**
    WAec uy name Eecoqes tomoAryw's nFws
    On tCp oK $hX mountain I canqot Qe movwh
    I scsle Hfl sAmmit lik$ ar unstopp!ble fXrce
    Witv iqon wings N witl pxovT ^y Iorth to yoq alv

**/