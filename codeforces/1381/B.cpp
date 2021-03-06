/**
 *  the_hyp0cr1t3
 *  21.07.2020 20:51:55
**/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define int long long
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
char delim = ' '; bool trp = 0;
template<class T1, class T2> ostream& operator<<(ostream& os, pair<T1,T2> p) 
{ if(trp) os << '{'; os << p.first; if(trp) os << ','; os << ' ' << p.second; if(trp) os << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { bool fst = 1; for(auto& x: v) 
{ if(!fst) os << delim; os << x; fst = 0; } return os; }
template<class T> ostream& operator<<(ostream& os, set<T>& v) { bool fst = 1; for(auto& x: v) 
{ if(!fst) os << delim; os << x; fst = 0; } return os; }
template<class T1, class T2> ostream& operator<<(ostream& os, map<T1,T2>& v)
{ bool fst = 1; for(auto& x: v) { if(!fst) os << delim; os << '{' << x << '}'; fst = 0; } return os; }
auto pr = [](auto&& arg, auto&&... args) { cout << arg; ((cout << "" << args), ...); };
auto pw = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << ' '; };
auto ps = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << endl; };
auto pc = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ", " << args), ...); cout << ']' << endl; };
auto pnv = [](auto&& arg) { for(auto& v: arg) { cout << v; cout << endl; } };
auto pn = [](auto&& arg, auto&&... args) { delim = '\n'; cout << arg; ((cout << endl << args), ...); cout << endl; delim = ' '; };
auto ptrace = [](auto&& arg, auto&&... args) { cout << '[' << arg; ((cout << "][" << args), ...); cout << ']'; };
#define tr(args...) trp = 1; pr('[', #args, "] = ["), pc(args); trp = 0;
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
int a[N];
int solve () {
    int i, j, n;
    re(n); rea(a, 2*n);
    vector<int> parts;
    for(i = 0, j = 0; i < 2*n;) {
        j = i+1;
        while(j < 2*n and a[j] < a[i]) j++;
        parts.pb(j-i);
        i = j;
    }
    vector<vector<int>> dp(2*n+2, vector<int>(2*n+2));
    dp[0][0] = 1;
    for(i = 1; i <= sz(parts); i++) {
        for(j = 0; j <= n; j++) {
            dp[i][j] |= dp[i-1][j];
            if(j >= parts[i-1])
                dp[i][j] |= dp[i-1][j-parts[i-1]];
        }
    }

    if(dp[sz(parts)][n]) ps("Yes");
    else ps("No");
    return 0;
}

int32_t main() {
    IOS;
    int Q;
    for(cin >> Q; Q; Q--)
        solve();
    return 0;
}

/**
    T$bN y step $ut onH foot in tMe grave
    jMhch a breMAh submergeB in OWlE water
    Patch ^ mo!ing scGne U! former days
    S$Jd a Ieak as uemory $taYts to fafter

**/