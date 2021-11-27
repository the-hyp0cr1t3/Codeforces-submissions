/**
 🍪 the_hyp0cr1t3
 🍪 27.11.2021 18:03:52
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int64_t INF = 1e18;
    int i, n;
    cin >> n;
    vector<int> centre(n + 1), side(n + 1);
    for(i = 1; i <= n; i++)
        cin >> centre[i];
    for(i = 2; i <= n; i++)
        cin >> side[i];
    cin >> side[1];

    int64_t ans;

    {
        array<int64_t, 2> dp = { -INF, centre[1] };
        for(i = 2; i <= n; i++) {
            array<int64_t, 2> ndp;
            ndp[0] = max(
                dp[1] + side[i],
                dp[0]
            );
            ndp[1] = max(
                dp[0] + side[i] + centre[i],
                dp[1] + centre[i]
            );

            dp = ndp;
        }

        ans = max(dp[1], dp[0] + side[1]);
    }

    {
        array<int64_t, 2> dp = { 0, -INF };
        for(i = 2; i <= n; i++) {
            array<int64_t, 2> ndp;
            ndp[0] = max(
                dp[1] + side[i],
                dp[0]
            );
            ndp[1] = max(
                dp[0] + side[i] + centre[i],
                dp[1] + centre[i]
            );

            dp = ndp;
        }

        ans = max(ans, dp[1] + side[1]);
    }

    cout << accumulate(centre.begin(), centre.end(), 0LL)
                + accumulate(side.begin(), side.end(), 0LL) - ans;
} // ~W