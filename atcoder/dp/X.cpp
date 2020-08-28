/**
 🍪 the_hyp0cr1t3
 🍪 28.08.2020 22:49:51
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

using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 2e4;
array<array<ll, N+5>, 2> dp;

struct box {
    int s, w, v;
    box(int s, int w, int v): s(s), w(w), v(v) {}
    bool operator<(const box& o) {
        return s+w < o.s+o.w;
    }
};

int32_t main() {
    aylmao
    int i, j, n; ll ans = 0;
    cin >> n;
    vector<box> a; a.reserve(n);
    for(i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        a.pb(y, x, z);
    }
    sort(all(a));

    dp[0].fill(-1);
    dp[0][0] = 0;

    for(i = 0; i < n; i++) {
        for(j = a[i].s; ~j; j--)
            if(~dp[0][j])
                dp[1][j+a[i].w] = max(dp[1][j+a[i].w], dp[0][j] + a[i].v);
        dp[0] = dp[1];
    }

    for(i = 0; i <= N; i++) 
        ans = max(ans, dp[1][i]);

    cout << ans;
    return 0;
}