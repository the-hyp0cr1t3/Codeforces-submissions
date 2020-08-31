/**
 🍪 the_hyp0cr1t3
 🍪 31.08.2020 16:54:51
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
const int INF = 2e9+2, MOD = 1e9+7;

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int N = 400 + 5;
ll cache[N][N];

int32_t main() {
    aylmao
    int n;
    cin >> n;
    vector<ll> a(n+1), pref(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << Y([&](auto dp, int l, int r) -> ll {
        if(l > r) return 0;
        if(l == r) return a[l];
        auto& ans = cache[l][r];
        if(~ans) return ans;
        ans = DESPACITO;
        for(int i = l; i < r; i++)
            chmin(ans, dp(l, i) + dp(i+1, r) + pref[r] - pref[l-1]);
        return ans;
    })(1, n) - pref[n];
    
    return 0;
}