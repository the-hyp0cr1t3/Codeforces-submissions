/**
 🍪 the_hyp0cr1t3
 🍪 29.09.2020 11:11:28
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

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
const int N = 19;
double p[N][N], cache[N][1<<N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; p[i][n] = 1, i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> p[i][j];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 1<<n; j++)
            cache[i][j] = -1;

    cout << fixed << setprecision(8);
    cout << Y([&](auto dp, int msk, int who) -> double {
        if(msk == (1<<n)-1) return who == 0;
        auto& ans = cache[who][msk];
        if(ans != -1) return ans;
        for(int i = 0; i < n; i++) {
            if(msk>>i&1) continue;
            double win = p[who][i] * dp(msk|1<<i, who);
            double lose = p[i][who] * dp(msk|1<<i, i);
            ans = max({ans, win + lose});
        } return ans;
    })(0, n) << '\n';
}