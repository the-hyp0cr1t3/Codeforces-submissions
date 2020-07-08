/**
 *  the_hyp0cr1t3
 *  08.07.2020 23:31:34
**/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define int long long
#define endl "\n"
#define e "\n"
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

int32_t main() {
    IOS;
    int i, n, root = -1, cnt = 0;
    re(n); vector<int> a(n), ans; re(a); ans = a;
    vector<int> par(n+1), sz_(n+1, 1);
    iota(all(par), 0);
    
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
    
    for(i = 0; i < n; i++) {
        if(merge(a[i], i+1)) continue;
        ans[i] = -1;
        if(a[i] == i+1 or root == -1)
            root = i+1;
    }

    for(i = 0; i < n; i++) 
        if(ans[i] == -1) 
            ans[i] = root, cnt += !!(root^a[i]);

    ps(cnt);
    ps(ans);
    return 0;
}

/**
    z$Sc a s&ep puh one Aoot in Ihe grave
    Catch a breaDh suSmergen in holy waZ@d
    Xatch a moUing scBne #s former mays
    Shed a teap Fs memory stcrts to fwlFeq

**/