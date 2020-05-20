#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
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
const int MOD = 1000000007;  //1e9 + 7
const int INF = 2000000000;  //2e9
const ll DESPACITO = 1000000000000000000;  //1e18
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
    // void pr(num Xx) { cout << Xx; }
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
const int N = 2e5 + 5;
struct Data {
    int tongue, cnt;
    Data() : tongue(-1), cnt(0) {};        // .
};
struct Mosquito {
    int pos, siz, id;
    Mosquito(int p, int s, int i) : pos(p), siz(s), id(i) {};
};

auto cmp = [] (const Mosquito& A, const Mosquito& B) {
    if(A.pos == B.pos) return A.id < B.id;
    return A.pos < B.pos;
};
set<Mosquito, decltype(cmp)> pending(cmp);

vector<pair<pii, int>> frogs;

struct SegTree {
    int N, curpending = 0;
    vector<Data> st;
    vector<pii> res;

    void merge(Data &cur, Data &l, Data &r) {
        cur.tongue = max(l.tongue, r.tongue);        // .
    }

    void build(int node, int L, int R) {
        if(L == R) {
            st[node].tongue = frogs[L-1].ff.ff + frogs[L-1].ff.ss;       // .
            return;
        }
        int M = (L+R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        merge(st[node], st[node*2], st[node*2+1]);
    }

    SegTree(int n) : N(n) {
        st.rsz(4*n + 5);
        res.rsz(n);
    }

    void Query(int node, int L, int R) {
        if(L == R) {
            res[frogs[L-1].ss] = mp(st[node].cnt, st[node].tongue-frogs[L-1].ff.ff);
            return;
        }
        int M = (L + R)/2;
        Query(node*2, L, M);
        Query(node*2 + 1, M + 1, R);
    } 

    bool Update(int node, int L, int R, Mosquito mosquito) {
        if(L == R) {
            auto ton = st[node].tongue;
            if(frogs[L-1].ff.ff > mosquito.pos)
                return false;
            if(ton < mosquito.pos)
                return false;
            ton += mosquito.siz;
            st[node].cnt++;
            int x = frogs[L-1].ff.ff;
            Mosquito search(x, -1, -1);
            auto it = pending.lb(search);
            // auto it = lb(all(pending), x, [] (const Mosquito& A, const int& B) {
                // return A.pos < B;
            // });
            auto it2 = it;
            while(it2 != pending.end() and it2->pos <= ton) {
                ton += it2->siz;
                st[node].cnt++;
                it2++;
            }
            st[node].tongue = ton;
            pending.erase(it, it2);
            return true;
        }
        if(st[node].tongue < mosquito.pos)
            return false;
        int M = (L + R)/2;
        bool ret = 0;
        if(st[node*2].tongue >= mosquito.pos)
            ret = Update(node*2, L, M, mosquito);
        else
            ret = Update(node*2 + 1, M + 1, R, mosquito);
        merge(st[node], st[node*2], st[node*2 + 1]);
        return ret;
    }

    vector<pii> query() {
        Query(1, 1, N);
        return res;
    }

    void update(Mosquito mosquito) {
        if(!Update(1, 1, N, mosquito))
            pending.ins(mosquito);
    }

};

int32_t main() {
    IOS;
    int i, n, m;
    re(n, m); frogs.rsz(n);
    for(i = 0; i < n; i++) 
        re(frogs[i].ff), frogs[i].ss = i;
    sort(all(frogs));
    SegTree st(n);
    st.build(1, 1, n);
    for(i = 0; i < m; i++) {
        int _p, _sz; re(_p, _sz);
        Mosquito mosquito(_p, _sz, i);
        st.update(mosquito);
    }
    auto ans = st.query();
    pn(ans);
    return 0;
}