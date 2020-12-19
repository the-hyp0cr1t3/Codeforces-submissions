/**
 🍪 the_hyp0cr1t3
 🍪 19.12.2020 15:26:46
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 105;
const int M = 1e4 + 5;
int a[N], b[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, k, n;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    double sumb = accumulate(b, b+n, 0);

    cout << fixed << setprecision(10);
    array<array<int, M>, N> dp;
    for(auto& x: dp) x.fill(-1);
    dp[0][0] = 0;

    for(i = 0; i < n; i++)
        for(k = n-1; ~k; k--)
            for(j = M-b[i]-1; ~j; j--)
                if(~dp[k][j]) chmax(dp[k+1][j+b[i]], dp[k][j] + a[i]);

    for(k = 1; k <= n; k++) {
        double ans = 0;
        for(j = 0; j < M; j++)
            if(~dp[k][j]) chmax(ans, min(1.0*dp[k][j]-j, 1.0*(sumb-j)/2) + j);
        cout << ans << ' ';
    }

} // ~W 