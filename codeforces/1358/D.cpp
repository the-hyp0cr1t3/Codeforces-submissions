/**
 🍪 the_hyp0cr1t3
 🍪 12.08.2020 02:40:05
**/
#include <bits/stdc++.h>
#define int long long
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
#define Lu(...) [&](auto&& u) { return __VA_ARGS__; }
const int N = 6e5 + 5;
int d[N], pref_days[N], pref_vals[N];

int32_t main() {
    k_II
    int i, n, k, ans = 0;
    auto f = Lu(u*(u+1)/2);
    re(n, k);
    for(i = n; i < 2*n; i++)
        re(d[i]), d[i-n] = d[i+n] = d[i];   
    for(i = 1; i < 3*n; i++) {
        pref_days[i] = pref_days[i-1] + d[i];
        pref_vals[i] = pref_vals[i-1] + f(d[i]);
    }

    auto mxmonth = [&](int days, int month) {
        int low = 0, high = n;
        while(low <= high) {
            int mid = low + high >> 1;
            int used = pref_days[month+mid] - pref_days[month];
            if(used < days) low = mid + 1;
            else high = mid - 1;
        }
        return month+high;
    };

    auto check = [&] (int x, int month) {
        int m = mxmonth(k-x, month);
        int res = f(d[month])-f(d[month]-x);
        res += pref_vals[m]-pref_vals[month];
        res += f((k-x)-(pref_days[m]-pref_days[month]));
        return res;
    };
    
    auto ternarySearch = [&] (int low, int high, int month) {
        while(high - low > 3) {
            int mid = low + high >> 1;
            if(check(mid, month) <= check(mid+1, month)) low = mid + 1;
            else high = mid;
        }
        for(int j = low; j <= high; j++) 
            chmax(ans, check(j, month));
    };
    
    for(i = n; i < 2*n; i++)
        ternarySearch(0, min(k, d[i-1]-1), i-1);

    ps(ans);
    
    W
}

/**
    tkok but dow't touch

**/