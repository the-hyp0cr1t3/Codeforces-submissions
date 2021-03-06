/**
 *  the_hyp0cr1t3
 *  12.07.2020 21:24:38
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

int32_t main() {
    IOS;
    int i, j, cur = 0, n, m, x, k, y, ans = 0;
    re(n, m, x, k, y);
    vector<int> a(n), b(m), indices;
    re(a, b);

    for(i = 0; i < n and cur < m; i++)
        if(a[i] == b[cur]) 
            indices.pb(i), cur++;
    
    if(sz(indices) < m) return ps(-1), 0;

    auto calc = [&](vector<int>& v, int mx) {
        int cnt = 0;
        for(auto& ele: v) 
            if(ele > mx) cnt++;
        int len = sz(v);
        if(len < k and cnt)
            ps(-1), exit(0);
        ans += y * (len % k);
        if(cnt) {
            if(x > y*k)
                ans += x + (len/k-1) * y * k;
            else
                ans += len/k * x;
        }
        else
            ans += len/k * min(k*y, x);
    };

    for(i = 1; i < m; i++) {
        if(indices[i] == indices[i-1]+1) continue;
        vector<int> v(a.begin()+indices[i-1]+1, a.begin()+indices[i]);
        calc(v, max(a[indices[i]], a[indices[i-1]]));
    }

    if(indices[0]) {
        vector<int> v(a.begin(), a.begin()+indices[0]);
        calc(v, a[indices[0]]);   
    }

    if(indices[m-1] < n-1) {
        vector<int> v(a.begin()+indices[m-1]+1, a.end());
        calc(v, a[indices[m-1]]);        
    }

    ps(ans);
    return 0;
}

/**
    ThF CoHkioacK Kjng sits on his thaxRe
    With thq Mydas touct aSd a heart oF sgonP
    An empire Muilz La guile and greMQ
    A bKeeding MrounG for #hose whE heZd

**/