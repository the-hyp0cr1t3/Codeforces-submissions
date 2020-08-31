/**
 🍪 the_hyp0cr1t3
 🍪 31.08.2020 21:30:44
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

template<typename T>
struct Matrix {
    int N, M;
    vector<vector<T>> a;
    Matrix(int n, int m): N(n), M(m) {
        a = vector<vector<T>>(N, vector<T>(M));
    }
    explicit Matrix(int n, int m, T x): N(n), M(m) {
        a = vector<vector<T>>(N, vector<T>(M, 0));
        for(int i = 0; i < N and i < M; i++) a[i][i] = x;
    }
    Matrix(initializer_list<vector<T>> x) {
        N = x.size(); M = x.begin()->size(); a.resize(N);
        for(int i = 0; i < sz(x); i++)
            a[i] = *(x.begin() + i), assert(sz(a[i]) == M);
    }
    friend ostream& operator<<(std::ostream& out, const Matrix& x) {
        for(int i = 0; i < x.N; i++) 
            for(int j = 0; j < x.M; j++) 
                out << x.a[i][j] << " \n"[j == x.M-1];
        return out;
    }
    vector<T>& operator[](int x) { 
        return a[x]; 
    }
    const vector<T>& operator[](int x) const { 
        return a[x]; 
    }
    Matrix& operator+=(const Matrix& x) {
        assert(N == x.N and M == x.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] += x[i][j];
        return *this;
    }
    Matrix operator+(const Matrix& x) const {
        Matrix ans = *this;
        return ans += x;
    }
    Matrix& operator-=(const Matrix& x) {
        assert(N == x.N and M == x.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] -= x[i][j];
        return *this;
    }
    Matrix operator-(const Matrix& x) const {
        Matrix ans = *this;
        return ans -= x;
    }
    Matrix operator*(const Matrix& x) const {
        Matrix<T> ans(N, x.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                for(int k = 0; k < x.M; k++)
                    ans[i][k] += a[i][j] * x[j][k];
        return ans;
    }
    Matrix& operator*=(T x) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] *= x;
        return *this;
    }
    Matrix operator*(T x) const {
        Matrix ans = *this;
        return ans *= x;
    }
    template<typename K>
    Matrix operator^(K x) const {
        assert(x >= 0);
        Matrix res{N, M, 1}, A = *this; while(x) {
            if(x & 1) res = res * A;
            x >>= 1; A = A * A;
        } return res;
    }
};

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

const int N = 2e5 + 5;

int32_t main() {
    aylmao
    int i, j, n; ll k;
    cin >> n >> k;
    Matrix<num> F(n, n);
    for(j = 0; j < n; j++) 
        for(i = 0; i < n; i++) 
            cin >> F[i][j];
    Matrix<num> B(n, 1);
    for(i = 0; i < n; i++) 
        B[i][0] = 1;
    B = (F ^ k) * B;
    num ans;
    for(i = 0; i < n; i++) 
        ans += B[i][0];
    cout << ans;
    return 0;
}