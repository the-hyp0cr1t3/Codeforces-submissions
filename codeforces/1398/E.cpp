/**
 🍪 the_hyp0cr1t3
 🍪 15.08.2020 08:39:22
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

const int N = 2e5 + 5;

int32_t main() {
    k_II
    int i, n; ll sumall = 0, summax = 0;
    re(n);
    set<int, greater<int>> fire, lightning, Max, rest;

    auto add = [&](int x) {
        sumall += x;
        int y = Max.empty()? 0 : *Max.rbegin();
        if(x > y) Max.erase(y), summax -= y, Max.ins(x), summax += x, rest.ins(y);
        else rest.ins(x);
    };

    auto rem = [&](int x) {
        sumall -= x;
        if(Max.erase(x)) summax -= x;
        else rest.erase(x);
    };

    auto balance = [&]() {
        while(sz(Max) > sz(lightning)) {
            auto x = *Max.rbegin();
            Max.erase(x);
            summax -= x;
            rest.ins(x);
        }
        while(sz(Max) < sz(lightning)) {
            auto x = *rest.begin();
            rest.erase(x);
            summax += x;
            Max.ins(x);
        }
    };

    while(n--) {
        int tp, d; re(tp, d);
        if(d > 0) {
            if(tp) lightning.ins(d);
            else fire.ins(d);
            add(d);
        }
        else {
            d = -d;
            if(tp) lightning.erase(d);
            else fire.erase(d);
            rem(d);
        }
        int x = lightning.empty()? 0 : *lightning.rbegin();
        if(x) rem(x);
        balance();
        ps(sumall + summax + x);
        if(x) add(x);
    }   
    
    W
}

/**
    LYke a Ibep put ote foet in the yrave
    CatEh a brDaty submYrgCd in holy wat#h
    Watcg a toeing scene of forPer Waos
    SheJ a tear as aeQo.y sHarts Ko fKlte&

**/