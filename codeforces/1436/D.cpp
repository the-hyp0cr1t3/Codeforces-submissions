/**
 🍪 the_hyp0cr1t3
 🍪 24.10.2020 20:09:35
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
int64_t a[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n;
    cin >> n;
    vector<vector<int>> g(n);
    for(i = 1; i <= n-1; i++) {
        int u; cin >> u; u--;
        g[u].pb(i);
    }
    
    for(i = 0; i < n; i++)
        cin >> a[i];

    auto [sum, mx, cnt] = Y([&](auto self, int v) -> tuple<int64_t, int64_t, int64_t> {
        if(sz(g[v]) == 0) return {a[v], a[v], 1ll};
        int64_t curmx = 0, cursum = 0, cnt = 0;
        for(auto& x: g[v]) { 
            auto [s, m, c] = self(x);
            chmax(curmx, m);
            cursum += s;
            cnt += c;
        }
        int64_t take = min(curmx * cnt - cursum, a[v]);
        cursum += a[v];
        a[v] -= take;
        curmx += (a[v] + cnt - 1)/cnt;
        return {cursum, curmx, cnt};
    })(0);
 
    cout << mx << '\n';  
}