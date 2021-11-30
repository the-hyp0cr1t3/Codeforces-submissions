/**
 🍪 the_hyp0cr1t3
 🍪 30.11.2021 18:56:12
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

template<int MOD>
struct Modint {
    using T = typename decay<decltype(MOD)>::type; T v;
    Modint(): v(0) {}
    template<typename U, typename = enable_if_t<is_integral<U>::value>>
    Modint(U v) { if(v < 0) v = v % MOD + MOD; if(v >= MOD) v %= MOD; this->v = static_cast<T>(v); }
    template<typename U, typename = enable_if_t<is_integral<U>::value>>
    explicit operator U() const { return static_cast<U>(v); }
    friend istream& operator>>(istream& in, Modint& m) { int64_t v_; in >> v_; m = Modint(v_); return in; }
    friend ostream& operator<<(ostream& os, const Modint& m) { return os << m.v; }

    static T inv(T a, T m) {
        T g = m, x = 0, y = 1;
        while(a != 0) {
            T q = g / a;
            g %= a; swap(g, a);
            x -= q * y; swap(x, y);
        } return x < 0? x + m : x;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif // x must be less than 2^32 * m
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
        asm("divl %4\n" : "=a" (quot), "=d" (rem) : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    Modint inv() const { return Modint(inv(v, MOD)); }
    Modint operator-() const { return Modint(v? MOD-v : 0); }
    Modint& operator++() { v++; if(v == MOD) v = 0; return *this; }
    Modint& operator--() { if(v == 0) v = MOD; v--; return *this; }
    Modint operator++(int) { Modint a = *this; ++*this; return a; }
    Modint operator--(int) { Modint a = *this; --*this; return a; }
    Modint& operator+=(const Modint& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Modint& operator-=(const Modint& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Modint& operator*=(const Modint& o) { v = fast_mod(uint64_t(v) * o.v); return *this; }
    Modint& operator/=(const Modint& o) { return *this *= o.inv(); }
    friend Modint operator+(const Modint& a, const Modint& b) { Modint res = a; res += b; return res; }
    friend Modint operator-(const Modint& a, const Modint& b) { Modint res = a; res -= b; return res; }
    friend Modint operator*(const Modint& a, const Modint& b) { Modint res = a; res *= b; return res; }
    friend Modint operator/(const Modint& a, const Modint& b) { Modint res = a; res /= b; return res; }
    friend bool operator==(const Modint& a, const Modint& b) { return a.v == b.v; }
    friend bool operator!=(const Modint& a, const Modint& b) { return a.v != b.v; }
    friend bool operator<(const Modint& a, const Modint& b) { return a.v < b.v; }
    friend bool operator>(const Modint& a, const Modint& b) { return a.v > b.v; }
    friend bool operator<=(const Modint& a, const Modint& b) { return a.v <= b.v; }
    friend bool operator>=(const Modint& a, const Modint& b) { return a.v >= b.v; }
    Modint operator^(int64_t p) {
        if(p < 0) return inv() ^ -p;
        Modint a = *this, res{1}; while(p > 0) {
            if(p & 1) res *= a;
            p >>= 1; if(p > 0) a *= a;
        } return res;
    }
};

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int MOD = 998244353;
    using mint = Modint<MOD>;

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    static vector<mint> fact{1, 1}, factinv{1, 1}, inv{0, 1};
    [](int N) {
        fact.reserve(N); factinv.reserve(N); inv.reserve(N);
        for(int z = fact.size(); z < N; z++) {
            inv.push_back(inv[MOD % z] * (MOD - MOD / z));
            fact.push_back(z * fact[z-1]);
            factinv.push_back(inv[z] * factinv[z-1]);
        }
    }(n);

    auto nCr = [](int n, int r) {
        return r < 0 or r > n? 0 : fact[n] * factinv[r] * factinv[n-r];
    };

    vector<int> sub(n, 1);
    vector<vector<mint>> big(n), smol(n);
    Y([&](auto dfs, int v, int p) -> void {
        big[v] = smol[v] = { 0, 1 };
        for(auto& x: g[v]) if(x ^ p) {
            dfs(x, v);
            vector<mint> nbig(sub[v] + sub[x] + 1), nsmol(sub[v] + sub[x] + 1);
            for(int kv = 1; kv <= sub[v]; kv++) {
                for(int k = kv; k <= kv + sub[x]; k++) {
                    nbig[k] += nCr(k - 1, kv - 1) * nCr(sub[v] + sub[x] - k, sub[v] - kv)
                                * big[v][kv] * smol[x][k - kv];
                    nsmol[k] += nCr(k - 1, kv - 1) * nCr(sub[v] + sub[x] - k, sub[v] - kv)
                                * smol[v][kv] * (big[x][sub[x]] - big[x][k - kv]);
                }
            }
            sub[v] += sub[x];
            big[v] = std::move(nbig);
            smol[v] = std::move(nsmol);
        }

        for(int i = 1; i <= sub[v]; i++) {
            big[v][i] += big[v][i - 1];
            smol[v][i] += smol[v][i - 1];
        }
    })(0, -1);

    cout << big[0][n] + smol[0][n];
} // ~W