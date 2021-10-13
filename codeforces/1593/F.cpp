/**
 🍪 the_hyp0cr1t3
 🍪 14.10.2021 00:23:46
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    static const int N = 100;

    int tests; cin >> tests;
    while(tests--) []() {
        int i, d, a, b, n, A, B; string s;
        cin >> n >> A >> B >> s;

        // dp[i][r-b][moda][modb] = 0 1 or 2
        // 40 * 80 * 40 * 40 * 2 = 1e8

        vector dp(n + 1, vector<vector<vector<int>>>(2 * n, vector<vector<int>>(A, vector<int>(B))));
        dp[0][0 + n][0][0] = -1;
        for(i = 0; i < n; i++) {
            for(d = -n + 1; d < n; d++) {
                for(a = 0; a < A; a++) {
                    for(b = 0; b < B; b++) {
                        if(!dp[i][d + n][a][b])
                            continue;
                        if(d + 1 + n < 2* n)
                            dp[i + 1][d + 1 + n][(a * 10 + s[i] - '0') % A][b] = N + a;
                        if(d - 1 + n >= 0)
                            dp[i + 1][d - 1 + n][a][(b * 10 + s[i] - '0') % B] = 2*N + b;
                    }
                }
            }
        }

        string ans(n, 'R');
        for(i = 0; i < n; i++) {
            if(dp[n][i + n][0][0]) {
                d = i + n; break;
            }
            if(dp[n][-i + n][0][0]) {
                d = -i + n; break;
            }
        }

        if(i == n)
            return cout << -1 << '\n', 0;

        for(i = n, a = b = 0; i; i--) {
            if(dp[i][d][a][b] >= 2*N) {
                ans[i - 1] = 'B';
                b = dp[i][d][a][b] - 2*N;
                d++;
            } else if(dp[i][d][a][b] >= N) {
                a = dp[i][d][a][b] - N;
                d--;
            } else {
                assert(false);
            }
        }

        return cout << ans << '\n', 0;
    }();

} // ~W