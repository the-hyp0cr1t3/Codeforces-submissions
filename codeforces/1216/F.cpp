/**
 🍪 the_hyp0cr1t3
 🍪 17.10.2020 15:00:45
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

template<class T, class U = int>
struct Segtree {
    int N; vector<T> st; vector<U> lazy; vector<bool> pending;
    Segtree(int N)
        : N(N), st(this->getmx(N)), lazy(st.size()), pending(st.size()) {}
    template<class Iter> Segtree(Iter beg, Iter end)
        : Segtree(end-beg) { build(1, 1, N, beg, end); }
    int getmx(int x) { int y = 1; for(y=1, x<<=1; y<x; y<<=1); return y+2; }

    template<class Iter>
    void build(int node, int L, int R, Iter beg, Iter end) {
        if(L == R) return st[node].set(*beg);
        int M = L + R >> 1;
        build(node<<1, L, M, beg, beg+(M-L));
        build(node<<1|1, M+1, R, beg+(M-L+1), end);
        st[node] = T(st[node<<1], st[node<<1|1]);
    }
    
    void prop(int node, int L, int R) {
        if(L != R) {
            pending[node<<1] = pending[node<<1|1] = true;
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        st[node].upd(lazy[node]);
        pending[node] = false; lazy[node] = U();
    }

    T Query(int node, int L, int R, int i, int j) {
        if(pending[node]) prop(node, L, R);
        if(i > R or j < L) return T();
        if(i <= L and j >= R) return st[node];
        int M = L + R >> 1;
        return T(Query(node<<1, L, M, i, j), 
                    Query(node<<1|1, M+1, R, i, j));
    } 

    void Update(int node, int L, int R, int i, int j, int64_t val) {
        if(pending[node]) prop(node, L, R);
        if(i > R or j < L) return;
        if(i <= L and j >= R) return lazy[node] += val, prop(node, L, R);
        int M = L + R >> 1;
        Update(node<<1, L, M, i, j, val);
        Update(node<<1|1, M+1, R, i, j, val);
        st[node] = T(st[node<<1], st[node<<1|1]);
    }

    auto query(int pos) { return Query(1, 1, N, pos, pos).val; }
    auto query(int l, int r) { return Query(1, 1, N, l, r).val; }
    void update(int pos, int64_t val) { Update(1, 1, N, pos, pos, val); }
    void update(int l, int r, int64_t val) { Update(1, 1, N, l, r, val); }
};

struct Lazy {
    int64_t lzy{DESPACITO};
    operator int64_t() const { return lzy; }
    void operator+=(int64_t rhs) { chmin(lzy, rhs); }
};

struct Node {
    int64_t val{DESPACITO};
    Node() = default;
    Node(const Node& l, const Node& r)
        : val(min(l.val, r.val)) {}
    void set(int64_t init) { val = init; }
    void upd(int64_t delta) { chmin(val, delta); }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, k; string s;
    cin >> n >> k >> s;
    
    Segtree<Node, Lazy> dp(n+1);
    dp.update(1, 0);
    for(i = 1; i <= n; i++) {
        if(s[i-1] == '1') {
            auto x = dp.query(max(0, i-k-1)+1, i-1+1);
            dp.update(i+1, min(n, i+k)+1, x + i);
        } dp.update(i+1, dp.query(i) + i);
    } cout << dp.query(n+1) << '\n';
}