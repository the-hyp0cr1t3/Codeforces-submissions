/**
 *  the_hyp0cr1t3
 *  29.07.2020 13:10:16
**/
#include <bits/stdc++.h>
// #define int long long
#define k_II ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DubYu return 0;
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
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll DESPACITO = 1e18;

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) { is >> p.first >> p.second; return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for(auto& x: v) is >> x; return is; }
auto re = [](auto&&... args) { (cin >> ... >> args); };
auto rea = [](auto&& A, auto sz_) { for(int i = 0; i < sz_; i++) cin >> A[i]; };
auto chmax = [](auto& A, auto&& B) { A = max(A, B); };
auto chmin = [](auto& A, auto&& B) { A = min(A, B); };
auto isLOC = [](auto A, string B = "") { return loc? A : B; };
template<class T1, class T2> ostream& operator<<(ostream& os, pair<T1,T2> p) 
{ os << isLOC("(") << p.first << isLOC(", ", " ") << p.second << isLOC(")"); return os; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { bool fst = 1; os << isLOC("{"); for(auto& x: v) 
{ if(!fst) os << isLOC(", ", " "); os << x; fst = 0; } os << isLOC("}"); return os; }
template<class T> ostream& operator<<(ostream& os, set<T>& v) { bool fst = 1; os << isLOC("{"); for(auto& x: v) 
{ if(!fst) os << isLOC(", ", " "); os << x; fst = 0; } os << isLOC("}"); return os; }
template<class T1, class T2> ostream& operator<<(ostream& os, map<T1,T2>& v) { bool fst = 1; os << isLOC("{"); for(auto& [x, y]: v)
{ if(!fst) os << isLOC(", ", " "); os << x << isLOC(": ", " ") << y; fst = 0; } os << isLOC("}"); return os; }
auto pr = [](auto&& arg, auto&&... args) { cout << arg; ((cout << "" << args), ...); };
auto pw = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << ' '; };
auto ps = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << endl; };
auto pc = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ", " << args), ...); cout << ']' << endl; };
auto pnv = [](auto&& arg) { for(auto& v: arg) { cout << v; cout << endl; } };
auto ptrace = [](auto&& arg, auto&&... args) { cout << '[' << arg; ((cout << "][" << args), ...); cout << ']'; };
#define tr(...) pr("(", __LINE__, ")[", #__VA_ARGS__, "]: ["), pc(__VA_ARGS__);
#define tra(arg, args...) __f(#arg, arg, args)
template<class arg, class ...args> void __f(const char* name, arg&& A, args&&... rest) { 
    const char* open = strchr(name, '['); cout.write(name, open-name);
     ptrace(rest...); cout << " = " << A << endl;
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

const int N = 1e5 + 5;
const int LG = 20;
int a[N];
vector<int> g[N];
int tin[N], tout[N], d[N], id[N], anc[LG][N];
vector<int> tree, bmask, order, sub;

struct Data {
    ll val;
    Data() : val(0) {}

    void init(int idx) {
        this->val = a[order[idx-1]];
    }

    void merge(const Data& l, const Data& r) {
        this->val = l.val + r.val;
    }

    void lazymerge(ll delta, ll len) {
        this->val += delta * len;
    }
};

struct SegTree {
    int N;
    vector<Data> st;
    vector<bool> cLazy;
    vector<ll> lazy;

    void build(int node, int L, int R) {
        if(L == R) {
            st[node].init(L);
            return;
        }
        int M = (L+R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        st[node].merge(st[node*2], st[node*2+1]);
    }

    SegTree(int n) : N(n) {
        st.resize(4*n + 5);
        cLazy.assign(4*n + 5, false);
        lazy.assign(4*n + 5, 0);
    }
    
    void propagate(int node, int L, int R) {
        if(L != R) {
            cLazy[node*2] = 1;
            cLazy[node*2 + 1] = 1;
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node]; 
        }
        st[node].lazymerge(lazy[node], R-L+1);
        cLazy[node] = 0;
        lazy[node] = 0;
    }

    Data Query(int node, int L, int R, int i, int j) {
        if(cLazy[node])
            propagate(node, L, R);
        if(i > R or j < L)
            return Data();
        if(i <= L and j >= R)
            return st[node];
        int M = (L + R)/2;
        Data left = Query(node*2, L, M, i, j);
        Data right = Query(node*2 + 1, M + 1, R, i, j);
        Data cur; cur.merge(left, right);
        return cur;
    } 

    void Update(int node, int L, int R, int i, int j, ll val) {
        if(cLazy[node])
            propagate(node, L, R);
        if(i > R or j < L)
            return;
        if(i <= L and j >= R) {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j, val);
        Update(node*2 + 1, M + 1, R, i, j, val);
        st[node].merge(st[node*2], st[node*2 + 1]);
    }

    ll query(int l, int r) {
        return Query(1, 1, N, l, r).val;
    }

    void update(int l, int r, int val) {
        Update(1, 1, N, l, r, val);
    }

};

int32_t main() {
    k_II
    int i, n, Q;
    re(n, Q); rea(a, n);
    for(i = 0; i < n-1; i++) {
        int u, v;
        re(u, v);
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    int cur = 0;
    order.reserve(n); sub.resize(n);
    auto dfs = Y([&](auto self, int v, int p) -> void {
        sub[v] = 1;
        id[v] = sz(order);
        tin[v] = cur++;
        order.pb(v);
        anc[0][v] = p;
        for(int k = 1; k < LG; k++) 
            anc[k][v] = ~anc[k-1][v]? anc[k-1][anc[k-1][v]] : -1;
        for(auto& x: g[v]) {
            if(x == p) continue;
            d[x] = d[v]+1;
            self(x, v);
            sub[v] += sub[x];
            cur++;
        }
        tout[v] = cur-1;
    });

    auto LCA = [&] (int u, int v) {
        if(d[u] < d[v])
            swap(u, v);
        for(int z = LG-1; ~z; --z) 
            if(d[u]-(1<<z) >= d[v])
                u = anc[z][u];
        if(u == v)
            return u;
        for(int z = LG-1; ~z; --z)
            if(anc[z][u]^anc[z][v])
                u = anc[z][u], v = anc[z][v];
        return anc[0][u];
    };
    
    dfs(0, -1);

    SegTree st(n);
    st.build(1, 1, n);

    auto isAnc = [&](int v, int u) {
        return tin[v] <= tin[u] and tout[v] >= tout[u];
    };

    int curv = 0;
    while(Q--) {
        int o; re(o);
        if(o == 1) {
            re(curv); curv--;
        }
        else if(o == 2) {
            int u, v; ll val; re(u, v, val); u--; v--;
            vector<int> tmp{LCA(curv, u), LCA(u, v), LCA(curv, v)};
            auto w = *min_element(all(tmp), [&](const auto& A, const auto& B) { 
                return d[A] > d[B]; 
            });
            if(w == curv)
                st.update(1, n, val);
            else if(isAnc(curv, w) or !isAnc(w, curv))
                st.update(id[w]+1, id[w]+sub[w], val);
            else {
                st.update(1, n, val);
                int y = curv;
                for(int z = LG-1; ~z; --z) 
                    if(d[y]-(1<<z) >= d[w]+1)
                        y = anc[z][y];
                st.update(id[y]+1, id[y]+sub[y], -val);
            }
        }
        else {
            int v; ll ans; re(v); v--;
            if(v == curv)
                ans = st.query(1, n);
            else if(isAnc(curv, v) or !isAnc(v, curv))
                ans = st.query(id[v]+1, id[v]+sub[v]);
            else {
                ans = st.query(1, n);
                int y = curv;
                for(int z = LG-1; ~z; --z) 
                    if(d[y]-(1<<z) >= d[v]+1)
                        y = anc[z][y];
                ans -= st.query(id[y]+1, id[y]+sub[y]);
            }
            ps(ans);
        }
    }
    
    DubYu
}

/**
    Salvation waitY wYthF!t Zepriev,
    I.m on a rfzRr's edge and Rt cutz my qeet
    Ac good aL life wipl ev$r Yet
    I wish fhat . coulS eZve it up anh go h#me

**/