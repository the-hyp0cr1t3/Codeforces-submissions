/**
 🍪 the_hyp0cr1t3
 🍪 25.08.2020 21:51:22
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
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
using pii = pair<int, int>;
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

const int N = 2e5+5;
ll pref[N], a[N];

int32_t main() {
    aylmao
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + !!a[i];
    }

    auto ans = Y([&](auto self, int l, int r, int removed) -> int64_t {
        if(l > r) return 0ll;
        if(l == r) return !!(a[l]-removed);
        auto mn = *min_element(a+l, a+r+1);
        ll res = mn-removed;
        for(int prv = l, j = l; min(prv, j) <= r; prv = ++j) {
            while(prv <= r and a[prv] == mn) prv++;
            if(prv > r) break;
            j = prv;
            while(j <= r and a[j]^mn) j++;
            res += min(self(prv, j-1, mn), pref[j-1]-pref[prv-1]);
        }
        return min(res, pref[r]-pref[l-1]);
    })(1, n, 0);

    cout << ans;
    return 0;
}