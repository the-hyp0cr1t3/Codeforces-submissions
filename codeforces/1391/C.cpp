/**
 🍪 the_hyp0cr1t3
 🍪 09.08.2020 20:44:46
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
struct num {
    typedef decay<decltype(MOD)>::type T;
    T v; 
    static T inv(T a, T m) { a %= m; return a == 1 ? 1 : (T)(m - ll(inv(m, a)) * ll(m) / a); } 
    num() : v(0) {}
    num(ll v_) {
        v = (-MOD < v_ && v_ < MOD) ? T(v_) : T(v_ % MOD);
        if (v < 0) v += MOD;
    }
    explicit operator T() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const num& n) { return out << T(n); }
    friend std::istream& operator >> (std::istream& in, num& n) { ll v_; in >> v_; n = num(v_); return in; } 
    friend bool operator == (const num& a, const num& b) { return a.v == b.v; }
    friend bool operator != (const num& a, const num& b) { return a.v != b.v; }
    num inv() const { num res; res.v = inv(v, MOD); return res; }
    num operator- () const { num res; res.v = v ? MOD-v : 0; return res; }
    num operator+ () const { return num(*this); }
    num& operator ++ () { v ++; if (v == MOD) v = 0; return *this; }
    num& operator -- () { if (v == 0) v = MOD; v --; return *this; }
    num& operator += (const num& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    num& operator -= (const num& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    num& operator *= (const num& o) { v = T(ll(v) * ll(o.v) % MOD); return *this; }
    num& operator /= (const num& o) { return *this *= o.inv(); }
    friend num operator ++ (num& a, int) { num r = a; ++a; return r; }
    friend num operator -- (num& a, int) { num r = a; --a; return r; }
    friend num operator + (const num& a, const num& b) { return num(a) += b; }
    friend num operator - (const num& a, const num& b) { return num(a) -= b; }
    friend num operator * (const num& a, const num& b) { return num(a) *= b; }
    friend num operator / (const num& a, const num& b) { return num(a) /= b; }
    friend bool operator < (const num& a, const num& b) { return a.v < b.v; }
    friend bool operator <= (const num& a, const num& b) { return a.v <= b.v; }
    friend bool operator > (const num& a, const num& b) { return a.v > b.v; }
    friend bool operator >= (const num& a, const num& b) { return a.v >= b.v; }
};
const int N = 1e6 + 50;
num fact[N], factinv[N], inv[N];

int32_t main() {
    k_II
    int i, n;
    re(n);
    fact[0] = factinv[0] = 1;
    fact[1] = factinv[1] = inv[1] = 1;
    for(int i = 2; i < N; i++) {
      fact[i] = fact[i-1] * num(i);
      inv[i] = num(-MOD/i) * inv[MOD%i];
      factinv[i] = factinv[i-1] * inv[i];
    }

    auto nCr = [&] (int n, int r) {
      return r > n? num(0) : fact[n] * factinv[r] * factinv[n-r];
    };
        
    num ans;
    for(i = 1; i <= n; i++)
        ans += nCr(n-1, i-1);
    ans = fact[n] - ans;
    ps(ans);
    W
}

/**
    Look bum don't tfucR

**/