/**
 🍪 the_hyp0cr1t3
 🍪 09.08.2020 21:21:30
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

using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 2e9;
constexpr ll DESPACITO = 1e18;

#ifdef LOCAL
    constexpr bool loc = true;
    #define tr(...) cout << "(" << __LINE__ << ")["#__VA_ARGS__"]: [", pr(__VA_ARGS__), cout << "]"
    #define tra(arg, args...) ptrace(#arg, arg, args)
#else
    constexpr bool loc = false;
    #define tr(...) "🍪"
    #define tra(...) "🍪"
#endif

#define SFINAE(x, ...)  template <class, class = void> struct x : false_type {}; template <class T> struct x<T, void_t<__VA_ARGS__>> : true_type {};
SFINAE(DefaultIO, decltype(cout << declval<T&>())) SFINAE(IsTuple, typename tuple_size<T>::type) SFINAE(Iterable, decltype(begin(declval<T>())))
auto chmax = [](auto& A, auto&& B) { A = max(A, B); };
auto chmin = [](auto& A, auto&& B) { A = min(A, B); };
auto isLOC = [](auto A, string B = "") { return loc? A : B; };
template<class T> void re(T& t) {
    if constexpr(DefaultIO<T>::value) cin >> t;
    else if constexpr(Iterable<T>::value) for(auto& x: t) re(x);
    else if constexpr(IsTuple<T>::value) apply([&](auto&... args) { (re(args), ...); }, t);
    else static_assert(DefaultIO<T>::value, "No matching type for read");
}
template<typename T> enable_if_t<is_pointer<T>::value, void> re(T beg, T end) { for(T it = beg; it != end; ++it) cin >> *it; }
template<class... Ts> void re(Ts&... ts) { (re(ts), ...); }
template<class T> constexpr void space(T) { if constexpr(Iterable<T>::value) cout << isLOC(",") << endl; else cout << isLOC(", "," "); }
template<class T> void pr(const T& t) {
    if constexpr(DefaultIO<T>::value) cout << t;
    else if constexpr(Iterable<T>::value) { cout << isLOC("{"); bool fst = 1; 
        for(auto&& x: t) { if(fst) fst = 0; else space(x); pr(x); } cout << isLOC("}"); }
    else if constexpr(IsTuple<T>::value) { cout << isLOC("("); apply([&](const auto&... args) 
        { bool fst = 1; ((fst ? (fst = 0, pr(args)) : (space(args), pr(args))), ...); }, t); cout << isLOC(")"); }
    else static_assert(DefaultIO<T>::value, "No matching type for print");
}
template<typename T> enable_if_t<is_pointer<T>::value, void> pr(T beg, T end) 
{ cout << isLOC("{"); for(T it = beg; it != end; ++it) { if(it != beg) space(*it); pr(*it); } cout << isLOC("}"); }
template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { pr(t), ((space(ts), pr(ts)), ...); }
template<class... Ts> void ps(Ts&&... ts) { pr(ts...); cout << endl; }
template<class... Ts> void pw(Ts&&... ts) { pr(ts...); cout << ' '; }
template<class T, class... Ts> void ptrace(const char* name, T&& A, Ts&&... rest) {
    const char* open = strchr(name, '['); cout.write(name, open-name);
    ((cout << '[' << rest << ']'), ...); cout << " = "; ps(A);
}

const int N = 1e6+5;
int a[N][3], dp[N][8], who3[8][2], who2[4][2];
const vector<vector<int>> V{{0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};
int32_t main() {
    k_II
    int i, j, k, n, m; char c;
    re(n, m);
    if(min(n, m) > 3) return ps(-1), 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            re(c); 
            m > n? a[j][i] = c-'0' : a[i][j] = c-'0';
        }
    }
    if(n < m) swap(n, m);
    // for(i = 0; i < n; i++) {
    //     for(j = 0; j < m; j++) 
    //         cout << a[i][j];
    //     ps("");
    // }
    if(m == 1) return ps(0), 0;

    who3[0][0] = 2;
    who3[0][1] = 5;

    who3[1][0] = 3;
    who3[1][1] = 4;

    who3[2][0] = 0;
    who3[2][1] = 7;

    who3[3][0] = 6;
    who3[3][1] = 1;

    who3[4][0] = 6;
    who3[4][1] = 1;

    who3[5][0] = 0;
    who3[5][1] = 7;

    who3[6][0] = 3;
    who3[6][1] = 4;

    who3[7][0] = 2;
    who3[7][1] = 5;

    who2[0][0] = 1;
    who2[0][1] = 2;

    who2[1][0] = 0;
    who2[1][1] = 3;

    who2[2][0] = 0;
    who2[2][1] = 3;

    who2[3][0] = 1;
    who2[3][1] = 2;

    if(m == 3) {
        for(i = 1; i <= n; i++) {
            for(j = 0; j < 8; j++) {
                int cost = 0;
                for(k = 0; k < 3; k++)
                    cost += a[i-1][k]^V[j][k];
                dp[i][j] = min(dp[i-1][who3[j][0]], dp[i-1][who3[j][1]]);
                dp[i][j] += cost;
            }
        }
        int ans = INF;
        for(i = 0; i < 8; i++) 
            chmin(ans, dp[n][i]);
        ps(ans);
    }
    else {
        for(i = 1; i <= n; i++) {
            for(j = 0; j < 4; j++) {
                int cost = 0;
                cost += a[i-1][0]^V[j][1];
                cost += a[i-1][1]^V[j][2];
                dp[i][j] = min(dp[i-1][who2[j][0]], dp[i-1][who2[j][1]]);
                dp[i][j] += cost;
            }
        }
        int ans = INF;
        for(i = 0; i < 4; i++) 
            chmin(ans, dp[n][i]);
        ps(ans);
    }
    W
}

/**
    Nes kevels, new devilv

**/