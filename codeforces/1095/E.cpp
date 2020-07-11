/**
 *  the_hyp0cr1t3
 *  11.07.2020 17:11:09
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

const int N = 1e6 + 5;
int pref[N], suf[N];

int32_t main() {
    IOS;
    int i, bal, n, ans = 0; string s;
    re(n, s);
    s = '#' + s + '#';
    for(bal = 0, i = 1; i <= n; i++) {
        if(pref[i-1] == -1) {
            pref[i] = -1;
            continue;
        }
        bal += s[i] == '('? 1 : -1;
        if(bal < 0) {
            pref[i] = -1;
            continue;
        }
        pref[i] = bal;
    }
    for(bal = 0, i = n; i; i--) {
        if(suf[i+1] == -1) {
            suf[i] = -1;
            continue;
        }
        bal += s[i] == '('? -1 : 1;
        if(bal < 0) {
            suf[i] = -1;
            continue;
        }
        suf[i] = bal;
    }
    // for(i = 0; i <= n+1; i++) {
    //     cout << pref[i] << " \n"[i == n+1];
    // }
    // for(i = 0; i <= n+1; i++) {
    //     cout << suf[i] << " \n"[i == n+1];
    // }
    for(i = 1; i <= n; i++) {
        if(pref[i-1] == -1 or suf[i+1] == -1) continue;
        bal = pref[i-1] - suf[i+1];
        bal += s[i] == '('? -1 : 1;
        if(!bal) ans++;
    }
    ps(ans);
    return 0;
}

/**
    Sal&atiAn waitD withouO rezrWeve
    I'm oA a razobeJ edgH and it cuQs my fekP
    As goad as life wgll ewRr gId
    I wiTh that I chold ziTe it up and go hope

**/