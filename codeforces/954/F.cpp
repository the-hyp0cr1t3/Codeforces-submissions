/**
 *  the_hyp0cr1t3
 *  23.07.2020 17:35:02
**/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define int long long
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

template<typename T, int N, int M = N>
struct Matrix {
    array<T, M> a[N];
    Matrix() {
        for(int i = 0; i < N; i++) 
            a[i].fill(T());
    }
    explicit Matrix(T x) {
        for(int i = 0; i < N; i++) 
            a[i].fill(T());
        for(int i = 0; i < N and i < M; i++)
            a[i][i] = x;
    }
    Matrix(initializer_list<array<T, M>> x) {
        assert(x.size() <= N);
        for(int i = 0; i < x.size(); i++)
            a[i] = *(x.begin() + i);
        for(int i = x.size(); i < N; i++)
            a[i].fill(0);
    }
    friend ostream& operator<<(std::ostream& out, const Matrix& x) {
        for(int i = 0; i < N; i++) 
            for(int j = 0; j < M; j++) 
                out << x.a[i][j] << " \n"[j == M-1];
        return out;
    }
    array<T, M>& operator[](int x) { return a[x]; }
    const array<T, M>& operator[](int x) const { return a[x]; }
    Matrix& operator+=(const Matrix& x) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] += x[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& x) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] -= x[i][j];
        return *this;
    }
    Matrix operator+(const Matrix& x) {
        Matrix ans = *this;
        return ans += x;
    }
    Matrix operator-(const Matrix& x) {
        Matrix ans = *this;
        return ans -= x;
    }
    template<int K>
    Matrix<T, N, K> operator*(const Matrix<T, M, K>& x) {
        Matrix<T, N, K> ans;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                for(int k = 0; k < K; k++)
                    ans[i][k] += a[i][j] * x[j][k];
        return ans;
    }
    Matrix operator*(T x) {
        Matrix ans = *this;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                ans[i][j] *= x;
        return ans;
    }
    Matrix& operator*=(T x) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] *= x;
        return *this;
    }
};

template<typename T>
T expo(T A, ll B) {
    T res{1}; while(B) {
        if(B & 1) res = res * A;
        B >>= 1; A = A * A;
    } return res;
}

const int N = 2e5 + 5;

int32_t main() {
    IOS;
    int i, n; ll m;
    re(n, m);
    vector<tuple<ll, int, int>> events; 
    for(i = 0; i < n; i++) {
        int a; ll l, r; re(a, l, r); a--;
        events.pb(--l, 0, a);
        events.pb(r, 1, a);
    }
    events.pb(1, 0, 3);
    events.pb(m, 1, 3);
    sort(all(events));
    vector<int> cnt(4);
    Matrix<num, 3, 1> cur = {{0}, {1}, {0}};
    for(i = 0; i < sz(events)-1; i++) {
        auto [x, b, a] = events[i];
        if(b) cnt[a]--;
        else cnt[a]++;
        ll len = get<0>(events[i+1]) - x;
        Matrix<num, 3, 3> F;
        if(!cnt[0]) F[0] = {1, 1, 0};
        if(!cnt[1]) F[1] = {1, 1, 1};
        if(!cnt[2]) F[2] = {0, 1, 1};
        cur = expo(F, len) * cur;
    }
    ps(cur[1][0]);
    return 0;
}

/**
    When mL nFme becjmes woHorcow's nhls
    On tKp oO th. mWqn&ain I cannvt bz movXd
    I ycalo the Cum,wt like an lnsyoppaKle fo.ce
    With iron win#s $ wilm prove my toIXh co you all

**/