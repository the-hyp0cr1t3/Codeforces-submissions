/**
 🍪 the_hyp0cr1t3
 🍪 24.10.2021 16:16:40
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int X = 8192, A = 5001;

    int i, a, n;
    cin >> n;
    array<vector<int>, A> occ;
    for(i = 0; i < n; i++) {
        cin >> a;
        occ[a].push_back(i);
    }

    array<int, X> dp;
    dp.fill(n);
    dp[0] = -1;

    for(a = 0; a < A; a++) {
        auto ndp = dp;
        for(i = 0; i < X; i++) {
            int j = upper_bound(occ[a].begin(), occ[a].end(), dp[i ^ a]) - occ[a].begin();
            if(j < occ[a].size())
                ndp[i] = min(ndp[i], occ[a][j]);
        }
        dp = std::move(ndp);
    }

    cout << X - ranges::count(dp, n) << '\n';
    for(i = 0; i < X; i++)
        if(dp[i] < n) cout << i << ' ';

} // ~W