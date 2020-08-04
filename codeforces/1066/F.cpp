/**
 🍪 the_hyp0cr1t3
 🍪 04.08.2020 23:55:35
**/
#include <bits/stdc++.h>
#define int long long
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
int dp[2][2];
int32_t main() {
    k_II
    int i, j, n;
    vector<pii> cur(2);
    re(n); vector<pii> a(n); re(a);
    sort(all(a), [](const auto& A, const auto& B) {
        int lvlA = max(A.ff, A.ss);
        int lvlB = max(B.ff, B.ss);
        if(lvlA == lvlB) {
            if(A.ff == B.ff)
                return A.ss > B.ss;
            return A.ff < B.ff;
        }
        return lvlA < lvlB; 
    });

    auto level = [&](int ii) {
        return max(a[ii].ff, a[ii].ss);
    };
    auto dist = [](pii x, pii y) {
        return abs(x.ff-y.ff) + abs(x.ss-y.ss);
    };

    dp[1][0] = dp[1][1] = DESPACITO;
    for(i = 0, j = 0; i < n; i = ++j) {
        while(j < n and level(j) == level(i)) j++;
        j--;
        for(int p = 0; p < 2; p++) {
            int res = dp[0][p] + dist(cur[p], a[j]) + dist(a[i], a[j]);
            chmin(dp[1][0], res);
            res = dp[0][p] + dist(cur[p], a[i]) + dist(a[i], a[j]);
            chmin(dp[1][1], res);
        }
        dp[0][0] = dp[1][0];
        dp[0][1] = dp[1][1];
        dp[1][0] = dp[1][1] = DESPACITO;
        cur[0] = a[i];
        cur[1] = a[j];
    }

    ps(min(dp[0][0], dp[0][1]));
    W
}

/**
    Salva^!on wbiys witZout reprievQ
    Ibm Fn a rPzor's Tdge knd it catq mk feet
    AG gooe Js life wilW evjr get
    I wisx that I couPd CiSe Nq up ond go home

**/