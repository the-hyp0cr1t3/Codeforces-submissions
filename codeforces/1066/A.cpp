/**
 🍪 the_hyp0cr1t3
 🍪 04.08.2020 22:42:30
**/
#include <bits/stdc++.h>
// #define int long long
#define k_II ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define W return 0;
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
constexpr int MOD = 1e9 + 7;
constexpr int INF = 2e9;
constexpr ll DESPACITO = 1e18;

#ifdef LOCAL
    constexpr bool loc = true;
    #define tr(...) pr("(", __LINE__, ")[", #__VA_ARGS__, "]: ["), pc(__VA_ARGS__)
    #define tra(arg, args...) ptrace(#arg, arg, args)
#else
    constexpr bool loc = false;
    #define tr(...) "🍪"
    #define tra(...) "🍪"
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
#define Vout(Con) template<class T> ostream& operator<<(ostream& os, Con<T>& v) { bool fst = 1; os << isLOC("{"); \
for(auto& x: v) { if(!fst) os << isLOC(", ", " "); os << x; fst = 0; } os << isLOC("}"); return os; }
#define Vout2(Con) template<class T1, class T2> ostream& operator<<(ostream& os, Con<T1,T2>& v) { bool fst = 1; os << isLOC("{"); \
for(auto& [x, y]: v) { if(!fst) os << isLOC(", ", " "); os << x << isLOC(": ", " ") << y; fst = 0; } os << isLOC("}"); return os; }
Vout(vector) Vout(set) Vout(multiset) Vout2(map)
#define Out(f, delim, lst) auto f = [](auto&& arg, auto&&... args) { cout << arg; ((cout << delim << args), ...); cout << lst; };
Out(pr, "", "") Out(pw, ' ', ' ') Out(ps, ' ', endl) Out(pc, ", ", "]" << endl)
auto pnv = [](auto&& arg) { for(auto& v: arg) { cout << v; cout << endl; } };
auto ptrace = [](const char* name, auto&& A, auto&&... rest) {
    const char* open = strchr(name, '['); cout.write(name, open-name);
    ((cout << '[' << rest << ']'), ...); cout << " = " << A << endl;
};

const int N = 2e5 + 5;

int solve () {
    int i, n, v, l, r;
    re(n, v, l, r); l--;
    int ans = n/v - (r/v - l/v);
    ps(ans);
    return 0;
}

int32_t main() {
    k_II
    int Q;
    for(cin >> Q; Q; Q--)
        solve();
    W
}

/**
    Th! ZocSroach King sHts oM his thloQ$
    With hhD Hfdai touch an. a heart nf spone
    hn empiCe bgild oD guWle ,nd dreed
    m dleeding KropnL for those who hRJd

**/