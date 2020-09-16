/**
 🍪 the_hyp0cr1t3
 🍪 17.09.2020 00:02:49
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
int a[N];

int32_t main() {
    aylmao
    int i, n, m, pos; int64_t ans = 0;
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = x == m? pos = i, 0 : x > m? 1 : -1;
    }
    map<int, int> cnt;
    int sum = 0;
    for(i = pos; i; i--) {
        sum -= a[i];
        cnt[sum]++;
    }

    for(i = pos, sum = 0; i <= n; i++) {
        sum += a[i];
        ans += cnt[sum];
        ans += cnt[sum-1];
    }

    cout << ans << '\n';
}