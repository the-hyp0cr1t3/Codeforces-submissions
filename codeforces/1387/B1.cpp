/**
 🍪 the_hyp0cr1t3
 🍪 01.08.2020 23:15:04
**/
#include <bits/stdc++.h>
// #define int long long
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
#define tr(...) pr("(", __LINE__, ")[", #__VA_ARGS__, "]: ["), pc(__VA_ARGS__)
#define tra(arg, args...) ptrace(#arg, arg, args)
#else
bool loc = false;
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
auto ptrace = [](const char* name, auto&& A, auto&&... rest) {
    const char* open = strchr(name, '['); cout.write(name, open-name);
    ((cout << '[' << rest << ']'), ...); cout << " = " << A << endl;
};

const int N = 2e5 + 5;

int32_t main() {
    k_II
    int i, n; ll sum = 0;
    re(n);
    vector<vector<int>> g(n);
    vector<int> deg(n), ans(n); iota(all(ans), 0);
    for(i = 0; i < n-1; i++) {
        int u, v;
        re(u, v);
        u--, v--;
        deg[u]++; deg[v]++;
        g[u].pb(v);
        g[v].pb(u);
    }
    queue<int> q;
    for(i = 0; i < n; i++)
        if(deg[i] == 1) q.push(i);
    while(!q.empty()) {
        auto x = q.front();
        q.pop();
        for(auto& v: g[x]) {
            if(deg[v] > 0) {
                if(ans[x] == x) swap(ans[v], ans[x]), sum += 2;
                if(--deg[v] == 1) q.push(v);
            }
        }
        if(ans[x] == x)
            swap(ans[x], ans[g[x][0]]), sum += 2;
        --deg[x];
    }
    ps(sum);
    for(auto& x: ans) x++;
    ps(ans);
    DubYu
}

/**
    ShAw ynlr cards aNd accepL
    Wgit you've been dcalt
    GDabdThn sr harbringer Wf sorbowX
    Pomr a dn,Ik, r$ise a g#ass
    And doast to GeHlth
    Is the trut! Doo haFd fCr Gs to hxLllow?

**/