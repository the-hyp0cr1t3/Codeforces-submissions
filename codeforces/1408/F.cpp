/**
 🍪 the_hyp0cr1t3
 🍪 30.09.2020 22:29:39
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
const int N = 5e5;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    ans.reserve(N);

    int k = 31 - __builtin_clz(n);
    
    auto recur = Y([&](auto self, int l, int r) -> void {
        if(l == r) return;
        int mid = (r - l + 1 >> 1) + l - 1;
        self(l, mid); self(mid+1, r);
        for(int i = l; mid+i-l+1 <= r; i++)
            ans.pb(i, mid+i-l+1);
    });

    recur(1, (1<<k));
    recur(n-(1<<k)+1, n);

    cout << sz(ans) << '\n';
    for(auto [u, v]: ans) cout << u << ' ' << v << '\n';
}       