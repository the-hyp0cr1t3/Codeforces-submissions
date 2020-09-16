/**
 🍪 the_hyp0cr1t3
 🍪 16.09.2020 23:08:47
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
int cache[N][3];

int32_t main() {
    aylmao
    int i, n; string s;
    cin >> s; n = sz(s);

    memset(cache, -1, sizeof(cache));
    cout << Y([&](auto dp, int idx, int mod) -> int {
        if(idx >= n)
            return 0;
        auto& ans = cache[idx][mod];
        if(~ans) return ans;
        int newmod = (s[idx]-'0'+mod) % 3;
        return ans = max(dp(idx+1, newmod), dp(idx+1, 0) + (newmod == 0));
    })(0, 0);
        
}