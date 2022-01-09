/**
 🍪 the_hyp0cr1t3
 🍪 09.01.2022 15:26:04
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
    auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
    auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, n, x, ans = 0, cnt = 0;
        cin >> n;
        vector<int64_t> a(n + 1);
        for(i = 1; i <= n; i++)
            cin >> a[i];
        cin >> x; a[1] -= x;

        vector<array<int, 3>> dp(n + 1);
        dp[1][1] = 1;
        for(i = 2; i <= n; i++) {
            a[i] += a[i - 1] - x;
            dp[i][0] = *R::max_element(dp[i - 1]);
            for(j = 0; j < 3; j++) {
                if(j > 0 and a[i] - (i == j? 0 : a[i - j - 1]) < 0) break;
                chmax(dp[i][min(j + 1, 2)], dp[i - 1][j] + 1);
            }
        }

        cout << *R::max_element(dp.back()) << '\n';
    }();

} // ~W