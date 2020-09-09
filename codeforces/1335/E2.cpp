/**
 🍪 thew6rst
 🍪 09.09.2020 15:44:47
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
const int INF = 2e9, MOD = 1e9+7;

const int N = 200;

int the_real_main() {
    int i, j, n, ans = 0;
    cin >> n;
    vector<vector<int>> a(N);
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        a[--x].pb(i);
    }

    for(i = 0; i < N; i++) {
        chmax(ans, sz(a[i]));
        for(j = 0; j < N; j++) {
            int l = 0, r = sz(a[i]) - 1;
            while(l < r) {
                int y = lower_bound(all(a[j]), a[i][r]) - upper_bound(all(a[j]), a[i][l]);
                chmax(ans, 2*l+2+y);
                l++, r--;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

int32_t main() {
    aylmao
    int Q; for(cin >> Q; Q; Q--) the_real_main();
    return 0;
}