/**
 🍪 the_hyp0cr1t3
 🍪 14.08.2020 21:13:49
**/
#include <bits/stdc++.h>
// #define int long long
#define k_II cin.tie(nullptr)->sync_with_stdio(false);
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
#define Lu(...) [&](auto&& u) { return __VA_ARGS__; }
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }

using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 2e9;
constexpr ll DESPACITO = 1e18;

#ifdef LOCAL
    constexpr bool loc = true;
    #define tr(...) cout << "(" << __LINE__ << ")["#__VA_ARGS__"]: [", pr(__VA_ARGS__), cout << "]\n"
    #define tra(arg, args...) ptrace(#arg, arg, args)
#else
    constexpr bool loc = false;
    #define tr(...) "🍪"
    #define tra(...) "🍪"
#endif

#define SFINAE(x, ...)  template <class, class = void> struct x : false_type {}; template <class T> struct x<T, void_t<__VA_ARGS__>> : true_type {};
SFINAE(DefaultIO, decltype(cout << declval<T&>())) SFINAE(IsTuple, typename tuple_size<T>::type) SFINAE(Iterable, decltype(begin(declval<T>())))
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };
auto isLOC = [](auto A, string B = "") { return loc? A : B; };
template<class T> void re(T& t) {
    if constexpr(DefaultIO<T>::value) cin >> t;
    else if constexpr(Iterable<T>::value) for(auto& x: t) re(x);
    else if constexpr(IsTuple<T>::value) apply([&](auto&... args) { (re(args), ...); }, t);
    else static_assert(DefaultIO<T>::value, "No read type");
}
template<typename T> void re(T* beg, T* end) { for(T* it = beg; it != end; ++it) cin >> *it; }
template<class... Ts> void re(Ts&... ts) { (re(ts), ...); }
template<class T> constexpr void space(T) { if constexpr(DefaultIO<T>::value) cout << isLOC(", "," "); else cout << isLOC(",") << endl; }
void pr() {}
template<class T> void pr(const T& t) {
    if constexpr(DefaultIO<T>::value) cout << t;
    else if constexpr(Iterable<T>::value) { cout << isLOC("{"); bool fst = 1; 
        for(auto&& x: t) { if(fst) fst = 0; else space(x); pr(x); } cout << isLOC("}"); }
    else if constexpr(IsTuple<T>::value) { cout << isLOC("("); apply([&](const auto&... args) 
        { bool fst = 1; ((fst ? (fst = 0, pr(args)) : (space(args), pr(args))), ...); }, t); cout << isLOC(")"); }
    else static_assert(DefaultIO<T>::value, "No write type");
}
template<typename T> void pr(T* beg, T* end) { cout << isLOC("{");
for(T* it = beg; it != end; ++it) { if(it != beg) space(*it); pr(*it); } cout << isLOC("}"); }
template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { pr(t), ((space(ts), pr(ts)), ...); }
template<class... Ts> void ps(Ts&&... ts) { pr(ts...); cout << endl; }
template<class... Ts> void pw(Ts&&... ts) { pr(ts...); cout << ' '; }
template<class T, class... Ts> void ptrace(const char* name, T&& A, Ts&&... rest) {
    const char* open = strchr(name, '['); cout.write(name, open-name);
    ((cout << '[' << rest << ']'), ...); cout << " = "; ps(A);
}

const int N = 200 + 5;
int dp[N][N][N];
int32_t main() {
    k_II
    int i, j, k, r, g, b, ans = 0;
    re(r, g, b);
    vector<int> a[3];
    a[0].reserve(r);
    a[1].reserve(g);
    a[2].reserve(b);
    for(i = 0; i < r; i++) {
        int x; re(x); a[0].pb(x);
    }
    for(i = 0; i < g; i++) {
        int x; re(x); a[1].pb(x);
    }
    for(i = 0; i < b; i++) {
        int x; re(x); a[2].pb(x);
    }
    for(i = 0; i < 3; i++) 
        sort(all(a[i]), greater<int>());
    for(i = 1; i <= r+1; i++) {
        for(j = 1; j <= g+1; j++) {
            for(k = 1; k <= b+1; k++) {
                if(i <= r and j <= g)
                    chmax(dp[i+1][j+1][k], dp[i][j][k] + a[0][i-1]*a[1][j-1]);
                if(k <= b and j <= g)
                    chmax(dp[i][j+1][k+1], dp[i][j][k] + a[2][k-1]*a[1][j-1]);
                if(i <= r and k <= b)
                    chmax(dp[i+1][j][k+1], dp[i][j][k] + a[2][k-1]*a[0][i-1]);
                chmax(ans, dp[i+1][j+1][k]);
                chmax(ans, dp[i][j+1][k+1]);
                chmax(ans, dp[i+1][j][k+1]);
            }
        }
    }
    for(i = 1; i <= r+1; i++)
        for(j = 1; j <= g+1; j++)
            for(k = 1; k <= b+1; k++)
                chmax(ans, dp[i][j][k]);
    ps(ans);    
    W
}

/**
    The CIckrCach qiTg sits on MiM throne
    WAth thE Mcdas Goucx and a hCart of stone
    An empire bWild on Quj!e and greeY
    A bleelung ground for b^YsO wwo hwed

**/