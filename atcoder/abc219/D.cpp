/**
 🍪 the_hyp0cr1t3
 🍪 18.09.2021 17:45:41
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, j, n, x, y;
    cin >> n >> x >> y;

    vector dp(x + 2, vector<int>(y + 2, INF));
    dp[0][0] = 0;

    while(n--) {
        int a, b; cin >> a >> b;
        for(i = x; ~i; i--)
            for(j = y; ~j; j--)
                chmin(dp[min(x, i + a)][min(y, j + b)], dp[i][j] + 1);
    }

    int ans = INF;
    for(i = x; i <= x+1; i++)
        for(j = y; j <= y+1; j++)
            chmin(ans, dp[i][j]);

    cout << (ans == INF? -1 : ans);

} // ~W