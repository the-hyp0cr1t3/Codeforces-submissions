/**
 🍪 the_hyp0cr1t3
 🍪 09.08.2020 20:09:46
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
template<class T> class Y {
    T f_;
public:
    template<class U> explicit Y(U&& f): f_(forward<U>(f)) {}
    template<class ...Args> decltype(auto) operator()(Args&&... args) {
        return f_(ref(*this), forward<Args>(args)...);
    }
}; 
template<class T> Y(T) -> Y<T>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int N = 1e4;

int solve() {
    int i, j, n, m, cur = 1;
    re(n, m); vector<string> a(n);
    re(a);
    
    vector<int> par(N), sz_(N, 1);
    iota(all(par), 0);
    
    auto getpar = [&] (int x) {
        int pp = x;
        while(par[pp] != pp)
            pp = par[pp];
        while(par[x] != x) {
            int z = par[x];
            par[x] = pp;
            x = z;
        }
        return pp;        
    };
    
    auto merge = [&] (int x, int y) {
        x = getpar(x);
        y = getpar(y);
        if (x == y) return false;
        if (sz_[x] < sz_[y]) swap(x, y);
        par[y] = x, sz_[x] += sz_[y];
        return true;
    };
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            int x = i, y = j;
            if(a[x][y] == 'L')
                y--;
            else if(a[x][y] == 'R')
                y++;
            else if(a[x][y] == 'U')
                x--;
            else
                x++;
            if(x < 0 or y < 0 or x >= n or y >= m) continue;
            merge(100*i+j, 100*x+y);
            // tr(i, j, x, y);
        }
    }
    
    set<int> ans;
    for(i = 0; i < n; i++) 
        for(j = 0; j < m; j++)
            ans.ins(getpar(100*i+j));
    ps(sz(ans)-1);
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
    Look buX KonTt todch

**/