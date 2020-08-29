/**
 🍪 the_hyp0cr1t3
 🍪 29.08.2020 12:17:21
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
// #define int long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int N = 300 + 5;
double cache[N][N][N];

int32_t main() {
    aylmao
    int i, j, k, n, cnt[4] = {};
    cin >> n;
    for(i = 0; i < n; i++) {
        int a; cin >> a; cnt[a]++;
    }
    memset(cache, -1, sizeof(cache));

    cout << fixed << setprecision(10) << Y([&](auto dp, int i, int j, int k) -> double {
        if(min({i, j, k}) < 0 or max({i, j, k}) == 0) return 0.0;
        auto& ans = cache[i][j][k];
        if(ans > 0) return ans;
        return ans = (n + dp(i-1, j, k)*i + dp(i+1, j-1, k)*j + dp(i, j+1, k-1)*k) / (i+j+k);
    })(cnt[1], cnt[2], cnt[3]);
    
    return 0;
}