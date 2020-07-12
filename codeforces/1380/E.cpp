/**
 *  the_hyp0cr1t3
 *  12.07.2020 22:34:59
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
bool trp = 0;
template<class T1, class T2> ostream& operator<<(ostream& os, pair<T1,T2> p) 
{ if(trp) os << '{'; os << p.first; if(trp) os << ','; os << ' ' << p.second; if(trp) os << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { bool fst = 1; for(auto& x: v) 
{ if(!fst) os << delim; os << x; fst = 0; } return os; }
template<class T> ostream& operator<<(ostream& os, set<T>& v) { bool fst = 1; for(auto& x: v) 
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
#define tr(args...) trp = 1; pr('[', #args, "] = ["), pc(args); trp = 0;
#define tra(arg, args...) __f(#arg, arg, args)
template<class arg, class ...args> void __f(const char* name, arg&& A, args&&... rest) { 
    const char* open = strchr(name, '['); cout.write(name, open-name);
     ptrace(rest...); cout << " = " << A << endl;
}

const int N = 2e5 + 5;

int32_t main() {
    IOS;
    int i, n, m, ans = 0;
    re(n, m);
    vector<set<pii>> towers(m+1);

    auto merge = [&] (pii p, auto& s) {
        if(!sz(s)) {
            s.ins(p);
            return;
        }
        auto it = s.upper_bound(p);
        vector<pii> kill;
        if(it != s.end() and it->ff == p.ss+1)
            p.ss = it->ss, kill.pb(*it);
        if(it != s.begin()) {
            --it;
            if(it->ss+1 == p.ff)
                p.ff = it->ff, kill.pb(*it);
        }
        ans -= sz(kill);
        for(auto& x: kill) 
            s.erase(x);
        s.ins(p);
    };

    for(i = 1; i <= n; i++) {
        int x; re(x); ans++;
        merge(mp(i, i), towers[x]);
    }

    ps(--ans);

    for(i = 1; i < m; i++) {
        int to, from; re(to, from);
        if(sz(towers[to]) < sz(towers[from])) 
            swap(towers[to], towers[from]);

        for(auto& p: towers[from])
            merge(p, towers[to]);

        towers[from].clear();
        ps(ans);
    }

    return 0;
}

/**
    Show your carKs and iXcepF
    $hat Wou've Neen pealt
    GDardian or ha$PQinger of sorrwId
    Pour a drinHi ruuse s glass
    !nd toAsg to Fealth
    Is the truth soo sard fok Qs to swTllod?

**/