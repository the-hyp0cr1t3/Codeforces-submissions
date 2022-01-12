/**
 🍪 the_hyp0cr1t3
 🍪 12.01.2022 17:55:43
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int A = 1e4 + 1, INF = 2e9;
    auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
    auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

    int i, j, k, n, l, K;
    cin >> n >> l >> K; ++K;
    vector<int> d(n), a(n);
    for(auto& x: d) cin >> x;
    for(auto& x: a) cin >> x;
    d.push_back(l);

    vector dp(K + 1, vector<int>(n, INF));
    dp[0][0] = 0;
    for(i = 0; i < n; i++) {
        vector ndp(K + 1, vector<int>(n, INF));
        for(k = 0; k < K; k++) {
            for(j = 0; j < n; j++) {
                if(dp[k][j] >= INF) continue;
                chmin(ndp[k][i], dp[k][j] + (d[i + 1] - d[i]) * a[i]);
                chmin(ndp[k + 1][j], dp[k][j] + (d[i + 1] - d[i]) * a[j]);
            }
        }
        dp = std::move(ndp);
    }

    int ans = INF;
    for(k = 0; k < K; k++)
        for(j = 0; j < n; j++)
            chmin(ans, dp[k][j]);

    cout << ans;

} // ~W