/**
 🍪 the_hyp0cr1t3
 🍪 14.08.2020 04:53:07
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
int p[N], a[N]; ll b[N];

template<class T, class U = int>
struct SegTree {
    int N; vector<T> st; vector<U> lazy; vector<bool> pending;
    SegTree(int N): N(N), st(vector<T>(4*N+5)), 
        lazy(vector<U>(4*N+5)), pending(vector<bool>(4*N+5)) {}

    void build(int node, int L, int R) {
        if(L == R) return st[node] <<= L;
        int M = L+R>>1;
        build(node*2, L, M); build(node*2+1, M+1, R);
        st[node] = T(st[node*2], st[node*2+1]);
    }
    
    void prop(int node, int L, int R) {
        if(L != R) {
            pending[node*2] = pending[node*2+1] = true;
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node]; 
        }
        st[node] << lazy[node];
        pending[node] = false;
        lazy[node] = U();
    }

    T Query(int node, int L, int R, int i, int j) {
        if(pending[node]) prop(node, L, R);
        if(i > R or j < L) return T();
        if(i <= L and j >= R) return st[node];
        int M = L+R>>1;
        return T(Query(node*2, L, M, i, j), Query(node*2+1, M+1, R, i, j));
    }

    void Update(int node, int L, int R, int i, int j, int val) {
        if(pending[node]) prop(node, L, R);
        if(i > R or j < L) return;
        if(i <= L and j >= R) return lazy[node] += val, prop(node, L, R);
        int M = L+R>>1;
        Update(node*2, L, M, i, j, val);
        Update(node*2+1, M+1, R, i, j, val);
        st[node] = T(st[node*2], st[node*2+1]);
    }

    auto query() { return Query(1, 1, N, 1, N).val; }
    void update(int pos, int val) { Update(1, 1, N, pos, pos, val); }
    void update(int l, int r, int val) { Update(1, 1, N, l, r, val); }
};

struct Node {
    ll val;
    Node(ll val = DESPACITO): val(val) {}    
    Node(const Node& l, const Node& r): val(min(l.val, r.val)) {}
    void operator<<=(int idx) { val = b[idx]; }
    void operator<<(const ll& lzy) { val += lzy; }
};

int32_t main() {
    k_II
    int i, n; ll sum = 0, ans = DESPACITO;
    re(n); re(p+1, p+n+1);
    for(i = 1; i <= n; i++)
        re(a[p[i]]);
    for(i = 1; i <= n+1; i++) {
        b[i] += sum;
        sum += a[i];
    }
    SegTree<Node, ll> st(n+1);
    st.build(1, 1, n+1);
    for(i = 1; i < n; i++) {
        st.update(1, p[i], a[p[i]]);
        st.update(p[i]+1, n+1, -a[p[i]]);
        chmin(ans, st.query());
    }
    ps(ans);
    W
}

/**
    New levClsu nwn devill

**/