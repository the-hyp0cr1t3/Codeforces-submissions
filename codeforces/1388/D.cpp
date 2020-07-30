/**
 *  the_hyp0cr1t3
 *  30.07.2020 21:15:24
**/
#include <bits/stdc++.h>
#define int long long
#define k_II ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DubYu return 0;
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

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
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
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { bool fst = 1; os << isLOC("{"); for(auto& x: v) 
{ if(!fst) os << isLOC(", ", " "); os << x; fst = 0; } os << isLOC("}"); return os; }
template<class T> ostream& operator<<(ostream& os, set<T>& v) { bool fst = 1; os << isLOC("{"); for(auto& x: v) 
{ if(!fst) os << isLOC(", ", " "); os << x; fst = 0; } os << isLOC("}"); return os; }
template<class T1, class T2> ostream& operator<<(ostream& os, map<T1,T2>& v) { bool fst = 1; os << isLOC("{"); for(auto& [x, y]: v)
{ if(!fst) os << isLOC(", ", " "); os << x << isLOC(": ", " ") << y; fst = 0; } os << isLOC("}"); return os; }
auto pr = [](auto&& arg, auto&&... args) { cout << arg; ((cout << "" << args), ...); };
auto pw = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << ' '; };
auto ps = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << endl; };
auto pc = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ", " << args), ...); cout << ']' << endl; };
auto pnv = [](auto&& arg) { for(auto& v: arg) { cout << v; cout << endl; } };
auto ptrace = [](auto&& arg, auto&&... args) { cout << '[' << arg; ((cout << "][" << args), ...); cout << ']'; };
#define tr(...) pr("(", __LINE__, ")[", #__VA_ARGS__, "]: ["), pc(__VA_ARGS__);
#define tra(arg, args...) __f(#arg, arg, args)
template<class arg, class ...args> void __f(const char* name, arg&& A, args&&... rest) { 
    const char* open = strchr(name, '['); cout.write(name, open-name);
     ptrace(rest...); cout << " = " << A << endl;
}

const int N = 2e5 + 5;
int a[N], b[N];

int solve () {
    int i, n;
    re(n); rea(a, n); rea(b, n);
    vector<int> g(n, -1), indeg(n), sum(a, a+n);
    for(i = 0; i < n; i++) {
        if(b[i] == -1) continue;
        g[i] = b[i]-1;
        indeg[b[i]-1]++;
    }

    set<pii> s;
    for(i = 0; i < n; i++)
        s.ins(mp(indeg[i], i));

    int total = 0;
    vector<int> ans, bads;
    ans.reserve(n);
    bads.reserve(n);
    while(!s.empty()) {
        auto [y, x] = *s.begin();
        s.erase(s.begin());
        // tr(x, total, sum[x]);
        if(sum[x] < 0) {
            bads.pb(x);
            // sum[x] = a[x];
            if(~g[x]) {
                s.erase(mp(indeg[g[x]], g[x]));
                indeg[g[x]]--;
                s.ins(mp(indeg[g[x]], g[x]));
            }
            continue;
        }
        ans.pb(x);
        total += sum[x];
        if(~g[x]) {
            sum[g[x]] += sum[x];
            s.erase(mp(indeg[g[x]], g[x]));
            indeg[g[x]]--;
            s.ins(mp(indeg[g[x]], g[x]));
        }
    }
    // tr(bads)
    // tr(ans)
    rev(bads);
    for(auto& x: bads) 
        total += sum[x];
    ans.ins(ans.end(), all(bads));
    for(auto& x: ans) 
        x++;
    ps(total);
    ps(ans);
    return 0;
}

int32_t main() {
    k_II
    int Q;
    for(Q = 1; Q; Q--)
        solve();
    DubYu
}

/**
    ae& Eeqels, new Vevils

**/