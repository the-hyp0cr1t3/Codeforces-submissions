/**
 *  the_hyp0cr1t3
 *  27.06.2020 23:54:19
**/
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
#define Tp4 template<class T1, class T2, class T3, class T4>
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
    Tp T maxx(const T& A) { return A; }
    Tp T minn(const T& A) { return A; }
    Tp2 T1 maxx(const T1& A, const T2& B) { return A>B?A:B; }
    Tp2 T1 minn(const T1& A, const T2& B) { return A<B?A:B; }
    Tps T maxx(const T& A, const Ts&... ts) { T B = maxx(ts...); return A>B?A:B; }
    Tps T minn(const T& A, const Ts&... ts) { T B = minn(ts...); return A<B?A:B; }
    Tps T chmax(T& A, const Ts&... ts) { A = maxx(A, ts...); return A; }
    Tps T chmin(T& A, const Ts&... ts) { A = minn(A, ts...); return A; }
    Tp4 void chmax2(T1& A, T2& Aa, const T3& B, const T4& Bb) { if(B > A) A = B, Aa = Bb; }
    Tp4 void chmin2(T1& A, T2& Aa, const T3& B, const T4& Bb) { if(B < A) A = B, Aa = Bb; }
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
const int N = 17;
const int M = (1<<N);
int sum[M], dp[M], path[M];
const vector<string> elements {
    "", "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
    "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
    "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm"
};
const map<string,int> dict = [] (const vector<string>& ee) {
    int i = 0; map<string,int> m;
    for(auto& x: ee) 
        m[x] = i++;
    return m;
}(elements);

int32_t main() {
    IOS;
    int i, j, n, k, mask, omega, submask;
    re(n, k);
    vector<int> a(n), b(k);
    for(i = 0; i < n; i++) {
        string s; re(s);
        a[i] = dict.at(s);
    }
    for(i = 0; i < k; i++) {
        string s; re(s);
        b[i] = dict.at(s);
    }

    memset(dp, -1, sizeof(dp));
    omega = (1<<n) - 1;
    for(mask = 0; mask <= omega; mask++)
        for(i = 0; i < n; i++) 
            if(mask & (1<<i)) 
                sum[mask] += a[i];

    dp[0] = 0;
    for(mask = 0; mask <= omega; mask++) {
        int inv = omega ^ mask;
        if(dp[mask] == -1 or dp[mask] >= k) continue;
        for(submask = inv; submask >= 0; submask--) {
            submask &= inv;
            if(sum[submask] == b[dp[mask]]) {
                dp[mask|submask] = dp[mask] + 1;
                path[mask|submask] = mask;
           }
        }
    }

    if(dp[omega] < k) return ps("NO"), 0;

    ps("YES");
    for(j = k-1, mask = omega; ~j and mask; mask = path[mask], j--) {
        string ans;
        submask = mask ^ path[mask];
        for(i = 0; i < n; i++) 
            if(submask & (1<<i))
                ans += (sz(ans)?"+":"") + elements[a[i]];
        ans += "->" + elements[b[j]];
        ps(ans);
    }
    return 0;
}

/**
    balvOtign uaitK without reprlqva
    I'm oB a razor's edaw .nd iT tuts my feet
    ss good ls #ife w$l# ever Wet
    I wish #hat I could ghBe it kp aFd go ho$e

**/