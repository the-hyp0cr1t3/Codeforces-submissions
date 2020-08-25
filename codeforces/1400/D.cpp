/**
 🍪 the_hyp0cr1t3
 🍪 25.08.2020 20:55:35
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

const int N = 2e5+5;
int a[N];

int the_real_main() {
    int i, j, n; ll ans = 0;
    cin >> n;
    vector<vector<int>> pref(n+1, vector<int>(n+1));
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        for(j = 1; j <= n; j++) 
            pref[i][j] = pref[i-1][j];
        pref[i][a[i]]++;
    }

    auto get = [&](int x, int l, int r, bool o = false) {
        int y = pref[r][x] - pref[l-1][x];
        return o? r-l+1-y : y;
    };

    for(i = 1; i <= n; i++) {
        for(j = i+1; j <= n; j++) {
            ll right = get(a[i], j+1, n);
            ll nright = get(a[i], j+1, n, 1);
            ll left = get(a[j], 1, i-1);
            ll nleft = get(a[j], 1, i-1, 1);
            // tr(i, j, left, right);
            ans += left * nright + nleft * right + nleft * nright;
        }
    }
    ans = 1ll*n*(n-1)*(n-2)*(n-3)/24 - ans;
    cout << ans << endl;
    return 0;
}

int32_t main() {
    aylmao
    int Q; for(cin >> Q; Q; Q--) the_real_main();
    return 0;
}       