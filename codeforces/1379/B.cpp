/**
 *  the_hyp0cr1t3
 *  19.07.2020 14:42:12
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

const int N = 2e5 + 5;

int solve () {
    int i, l, r, m;
    re(l, r, m);
    if(m >= l and m <= r)
        ps(m, l, l);
    else if(m < l) {
        for(i = l; i <= r; i++) 
            if(l+i-m >= l and l+i-m <= r)
                return ps(i, l, i+l-m), 0;
        assert(false);
    }
    else {
        int best = DESPACITO, ans = -1;
        for(i = l; i <= r; i++) {
            int mod = m % i;
            mod = min(mod, i-mod);
            if(mod < best)
                best = mod, ans = i;
        }
        int mod = m % ans;
        // tr(mod, ans-mod);
        if(mod <= ans-mod)
            ps(ans, best+l, l);
        else
            ps(ans, l, ans-mod+l);
    }
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
    bGke a step put on! CQdt in the grave
    Catch T brelth subb&rgtd in holy wOCer
    Xatch a movzng sMNne of jPrm!r dRys
    Ched a teaB as memorH s$arns to Falter

**/