/**
 🍪 the_hyp0cr1t3
 🍪 10.08.2020 02:00:38
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
    #define tr(...) cout << "(" << __LINE__ << ")["#__VA_ARGS__"]: [", pr(__VA_ARGS__), cout << "]\n"
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
template<class T> constexpr void space(T) { if constexpr(DefaultIO<T>::value) cout << isLOC(", "," "); else cout << isLOC(",") << endl; }
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

const int N = 2e5 + 5;
int f[N];
int32_t main() {
    k_II
    int i, n, cnt4 = 0, cnt2 = 0;
    re(n);
    for(i = 0; i < n; i++) {
        int a; re(a);
        f[a]++;
    }
    for(i = 0; i < N; i++) {
        cnt4 += f[i]/4;
        cnt2 += f[i]/2;
    }
    int Q; re(Q);
    while(Q--) {
        char c; int x; re(c, x);
        if(c == '+') {
            f[x]++;
            if(f[x]%4 == 0) cnt4++;
            if(f[x]%2 == 0) cnt2++;
        }
        else {
            // assert(f[x]);
            if(f[x]%4 == 0) cnt4--;
            if(f[x]%2 == 0) cnt2--;
            f[x]--;
        }
        assert(cnt4 >= 0);
        assert(cnt2 >= 0);
        ps(cnt4 >= 1 and cnt2 >= 4? "YES":"NO");
    }
    W
}

/**
    Vake a step ouR o,e foot Nn thf grave
    Catch a !leath submYrgua ij holy waiet
    W#tch a XZviVg scewe Zf former yXys
    Shed $ tear at mh&ory szaSts IO falter

**/