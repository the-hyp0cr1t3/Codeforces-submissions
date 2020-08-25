/**
 🍪 the_hyp0cr1t3
 🍪 25.08.2020 12:18:15
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

const int N = 5000+5;
int a[N], vis[N][3];
ll pref[N], cache[N][3], path[N][3];

int32_t main() {
    aylmao
    int n; ll res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }

    Y([&](auto dp, int idx, int p) -> ll {
        if(p == 3) return pref[idx-1] - pref[n];
        ll& ans = cache[idx][p];
        if(vis[idx][p]++) return ans;
        ans = -DESPACITO;
        for(int i = idx; i <= n+1; i++) {
            ll sum = pref[i-1] - pref[idx-1];
            if(p == 1) sum = -sum;
            if(chmax(ans, sum + dp(i, p+1)))
                path[idx][p] = i;
        }
        return ans;
    })(1, 0);

    vector<int> ans;
    int idx = path[1][0];
    ans.pb(idx-1);
    idx = path[idx][1];
    ans.pb(idx-1);
    idx = path[idx][2];
    ans.pb(idx-1);

    for(auto& x: ans) 
        cout << x << " ";
    return 0;
}