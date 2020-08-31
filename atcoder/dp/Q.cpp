/**
 🍪 the_hyp0cr1t3
 🍪 31.08.2020 20:26:17
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define endl '\n'
#define pb emplace_back
// #define int int64_t
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

template<class T>
struct Segtree {
    int N; vector<T> st;
    Segtree(int N): N(N) {
        int SZ = 1; for(SZ = 1; SZ < N; SZ <<= 1);
        st.resize(2*SZ+2);
    }
    template<class Iter> Segtree(Iter beg, Iter end): N(end-beg) {
        int SZ = 1; for(SZ = 1; SZ < N; SZ <<= 1);
        st.resize(2*SZ+2); build(1, 1, N, beg, end);
    }

    T Query(int node, int L, int R, int i, int j) {
        if(i > R or j < L) return T();
        if(i <= L and j >= R) return st[node];
        int M = L+R>>1;
        return T(Query(node*2, L, M, i, j), Query(node*2+1, M+1, R, i, j));
    } 

    void Update(int node, int L, int R, int pos, ll val) {
        if(L == R) return st[node] << val;
        int M = L+R>>1;
        pos <= M? Update(node*2, L, M, pos, val) : Update(node*2+1, M+1, R, pos, val);
        st[node] = T(st[node*2], st[node*2+1]);
    }

    auto query(int l, int r) { return Query(1, 1, N, l, r).val; }
    void update(int pos, ll val) { Update(1, 1, N, pos, val); }
};

struct Node {
    ll val;
    Node(ll val = 0) : val(val) {}    
    Node(const Node& l, const Node& r)
        : val(max(l.val, r.val)) {}
    void operator<<=(int init) { val = init; }
    void operator<<(ll delta) { chmax(val, delta); }
};

const int N = 2e5 + 5;
int a[N], h[N];

int32_t main() {
    aylmao
    int i, n;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> h[i];
    for(i = 0; i < n; i++) 
        cin >> a[i];

    i = 0;
    map<int, int> coords;
    for(auto& x: h) 
        coords[x];
    for(auto& x: coords) 
        x.second = ++i;
    for(auto& x: h) 
        x = coords[x];

    Segtree<Node> st(n);
    for(int i = 0; i < n; i++) {
        auto x = st.query(1, h[i]-1);
        st.update(h[i], x+a[i]);
    }
    cout << st.query(1, n);
    return 0;
}