#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define int long long
using namespace std;
#define e "\n"
#define endl "\n"
#define Tp template<class T>
#define Tp2 template<class T1, class T2>
#define Tps template<class T, class... Ts>
#define Tps2 template<class T1, class T2, class... Ts>
#define ff first
#define ss second
#define rev(Aa) reverse(Aa.begin(),Aa.end())
#define all(Aa) Aa.begin(),Aa.end()
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins insert
#define mp make_pair
#define pb emplace_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define sz(Xx) (int)(Xx).size()
typedef long long ll;
typedef long double ld;
typedef double db;
using pii = pair<int, int>;
const int MOD = 1000000009;  //1e9 + 9
const int INF = 2000000000;  //2e9
const ll DESPACITO = 1000000000000000000;  //1e18
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

namespace minmax {
    Tp T max(T&& A) { return A; }
    Tp T min(T&& A) { return A; }
    Tp T max(T&& A, T&& B) { return A>B?A:B; }
    Tp T chmin2(T&& A, T&& B) { return A<B?A:B; }
    Tps T max(T&& A, Ts&&... ts) { T B = max(ts...); return A>B?A:B; }
    Tps T min(T&& A, Ts&&... ts) { T B = min(ts...); return A<B?A:B; }
    Tps T chmax(T&& A, Ts&&... ts) { A = max(A, ts...); return A; }
    Tps T chmin(T&& A, Ts&&... ts) { A = min(A, ts...); return A; }
    Tp2 void chmin2(T1&& A, T2&& Aa, T1&& B, T2&& Bb) { if(B < A) A = B, Aa = Bb; }
    Tp2 void chmax2(T1&& A, T2&& Aa, T1&& B, T2&& Bb) { if(B > A) A = B, Aa = Bb; }
}
namespace input { 
    Tp void re(T&& Xx) { cin >> Xx; }
    Tp2 void re(pair<T1,T2>& Pp) { re(Pp.first); re(Pp.second); }
    Tp void re(vector<T>& Aa) { for(int i = 0; i < sz(Aa); i++) re(Aa[i]); }
    Tp2 void rea(T1&& Aa, T2 t) { for(int i = 0; i < t; i++) re(Aa[i]); }
    Tps2 void rea(T1&& Aa, T2 t, Ts&&... ts) { rea(Aa, t); rea(ts...); }
    Tp2 void rea1(T1&& Aa, T2 t) { for(int i = 1; i <= t; i++) re(Aa[i]); }
    Tps2 void rea1(T1&& Aa, T2 t, Ts&... ts) { rea1(Aa, t); rea1(ts...); }
    Tps void re(T&& t, Ts&... ts) { re(t); re(ts...); }
}
namespace output {
    void pr(int32_t Xx) { cout << Xx; }
    void pr(num Xx) { cout << Xx; }
    void pr(bool Xx) { cout << Xx; }
    void pr(long long Xx) { cout << Xx; }
    void pr(long long unsigned Xx) { cout << Xx; }
    void pr(double Xx) { cout << Xx; }
    void pr(char Xx) { cout << Xx; }
    void pr(const string& Xx) { cout << Xx; }
    void pr(const char* Xx) { cout << Xx; }
    void pr(const char* Xx, size_t len) { cout << string(Xx, len); }
    void ps() { cout << endl; }
    void pn() { /*do nothing*/ }
    void pw() { pr(" "); }
    void pc() { pr("]"); ps(); }
    Tp2 void pr(const pair<T1,T2>& Xx) { pr(Xx.first); pw(); pr(Xx.second);}
    Tp void pr(const T&);
    bool parse(const char* t) { if(t == e) return true; return false;}
    Tp bool parse(T&& t) { return false;}
    Tp2 bool parsepair(const pair<T1,T2>& Xx) { return true; }
    Tp bool parsepair(T&& t) { return false;}
    Tp2 void psa(T1&& Aa, T2 t) { for(int i = 0; i < t; i++) pr(Aa[i]), pw(); ps(); }
    Tp2 void pna(T1&& Aa, T2 t) { for(int i = 0; i < t; i++) pr(Aa[i]), ps(); }
    Tp2 void psa2(T1&& Aa, T2 t1, T2 t2) { for(int i = 0; i < t1; i++) {for(int j = 0; j < t2; j++) pr(Aa[i][j]), pw(); ps();} }
    Tp void pr(const T& Xx) { if(!sz(Xx)) return; bool fst = 1; bool op = 0; if (parsepair(*Xx.begin())) op = 1; for (const auto& Aa: Xx) {if(!fst) pw(); if(op) pr("{"); pr(Aa), fst = 0; if(op) pr("}"); } }
    Tps void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
    Tps void ps(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) {if (!parse(t)) pw(); } ps(ts...); }
    Tp void pn(const T& t) { for (const auto& Aa: t) ps(Aa); }
    Tps void pw(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pw(); pw(ts...); }
    Tps void pc(const T& t, const Ts&... ts) { bool op = 0; if (parsepair(t)) op = 1; if(op) pr("{"); pr(t); if(op) pr("}"); if (sizeof...(ts)) pr(", "); pc(ts...); }
    namespace trace {
        #define tr(Xx...) pr("[",#Xx,"] = ["), pc(Xx);
        #define tra(Xx, y...) __f0(#Xx, Xx, y)
        #define tran(Xx, n) __fn(n, #Xx, Xx) // TO DO~ variadic multidimensional
        Tp2 void __f(const char* name, const T1& Xx, const T2& y){ pr("[",y,"] = "); ps(Xx); }
        Tps2 void __f(const char* name, const T1& Xx, const T2& y, const Ts&... rest){ const char *open = strchr(name, '['); pr("[",y,"]"); __f(open+1, Xx, rest...); }
        Tps2 void __f0(const char* name, const T1& Xx, const T2& y, const Ts&... rest){ const char *open = strchr(name, '['); pr(name, size_t(open-name)); __f(name, Xx, y, rest...); }
        Tp void __fn(int n, const char* name, const T& Xx) { for(int i = 0; i < n; i++) pr(name), __f(name, Xx[i], i); }
    }
}
using namespace minmax;
using namespace input;
using namespace output;
using namespace output::trace;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3e5 + 5;
vector<int> a;
num fib[N];

struct lazyData {
    num f1, f2;
    lazyData() : f1(0), f2(0) {}
    lazyData(int _f1, int _f2) : f1(_f1), f2(_f2) {}

    num get_kth_value(int k) const {
        if(k == 1) return f1;
        if(k == 2) return f2;
        num res = this->f1 * fib[k-2] + this->f2 * fib[k-1];
        return res;
    }

    void updatelazy(const lazyData& flazy) {
        this->f1 += flazy.f1;
        this->f2 += flazy.f2;
    }

    lazyData nxt(int k) {
        lazyData ret = *this;
        ret.f1 = this->get_kth_value(k);
        ret.f2 = this->get_kth_value(k+1);
        return ret;
    }
};

struct Data {
    num sum;
    Data() : sum(0) {}

    void init(int idx) {
        this->sum = a[idx-1];
    }

    void merge(const Data& l, const Data& r) {
        this->sum = l.sum + r.sum;
    }

    void lazymerge(const lazyData& flazy, int len) {
        num res = flazy.get_kth_value(len+2) - flazy.f2;
        this->sum += res;
    }
};

struct SegTree {
    int N;
    vector<Data> st;
    vector<bool> cLazy;
    vector<lazyData> lazy;

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
        st.rsz(4*n + 5);
        cLazy.assign(4*n + 5, false);
        lazy.rsz(4*n + 5);
    }
    
    void propagate(int node, int L, int R) {
        if(L != R) {
            cLazy[node*2] = 1;
            cLazy[node*2 + 1] = 1;
            lazy[node*2].updatelazy(lazy[node]);
            lazyData tmp = lazy[node];
            int M = (L+R)/2;
            lazy[node*2 + 1].updatelazy(lazy[node].nxt(M-L+2)); 
        }
        st[node].lazymerge(lazy[node], R-L+1);
        cLazy[node] = 0;
        lazy[node] = lazyData();
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

    void Update(int node, int L, int R, int i, int j, lazyData& cur) {
        if(cLazy[node])
            propagate(node, L, R);
        if(i > R or j < L)
            return;
        if(i <= L and j >= R) {
            cLazy[node] = 1;
            lazy[node] = cur;
            cur = cur.nxt(R-L+2);
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j, cur);
        Update(node*2 + 1, M + 1, R, i, j, cur);
        st[node].merge(st[node*2], st[node*2 + 1]);
    }

    num query(int l, int r) {
        return Query(1, 1, N, l, r).sum;
    }

    void update(int l, int r) {
        lazyData flazy = lazyData(1, 1);
        Update(1, 1, N, l, r, flazy);
    }

};

int32_t main() {
    IOS;
    int i, n, m;
    re(n, m); a.rsz(n); re(a);
    fib[1] = fib[2] = 1;
    for(i = 3; i < N; i++) 
        fib[i] = fib[i-1] + fib[i-2];
    SegTree st(n);
    st.build(1, 1, n);
    while(m--) {
        int o, l, r; re(o, l, r);
        if(o == 1)
            st.update(l, r);
        else
            ps(st.query(l, r));
    }
    return 0;
}