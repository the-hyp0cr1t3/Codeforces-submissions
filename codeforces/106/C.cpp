/**
 *  the_hyp0cr1t3
 *  04.07.2020 13:37:13
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
char delim = ' ';
template<class T1, class T2> ostream& operator<<(ostream& os, pair<T1,T2>& p) { os << p.first << ' ' << p.second; return os; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { if(v.size()) { os << v[0]; for(int i = 1; i < (int)v.size(); i++) os << delim << v[i]; } return os; }
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

const int N = 2e3 + 5;
int dp[N];
int32_t main() {
    IOS;
    int i, n, m, c0, d0;
    re(n, m, c0, d0);
    vector<pii> have;
    for(i = 0; i < m; i++) {
        int a, b, c, d;
        re(a, b, c, d);
        while(a >= b) {
            have.pb(c, d);
            a -= b;
        }
    }
    for(auto& [c, d]: have) {
        for(i = n-c; i >= 0; i--) 
            chmax(dp[i+c], dp[i]+d);
    }
    for(i = 0; i <= n-c0; i++)
        chmax(dp[i+c0], dp[i]+d0);
    ps(*max_element(dp, dp+N));
    return 0;
}

/**
    shen my namr bqcomey n^morrow's newi
    Vn thp oQ the mountapC s Aannot be moLed
    I soalD the qummiz like !n unsqopQa.le j,rce
    W^th iron w!@gs I will prove mf worxl ^o xAu aUl

**/