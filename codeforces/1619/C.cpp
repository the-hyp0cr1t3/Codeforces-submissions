/**
 🍪 the_hyp0cr1t3
 🍪 12.01.2022 15:33:42
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

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j; string a, s;
        cin >> a >> s;
        R::reverse(a); R::reverse(s);
        int n = s.size(), m = a.size();
        a.resize(n, '0');
        vector dp(n + 1, vector<int>(n + 1));
        dp[0][0] = -1;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(!dp[i][j]) continue;
                if(s[j] - a[i] >= 0)
                    dp[i + 1][j + 1] = 10 + s[j] - a[i];
                if(j + 2 <= n) {
                    int d = 10 * (s[j + 1] - '0') + s[j] - a[i];
                    if(s[j + 1] == '1' and 0 <= d and d <= 9)
                        dp[i + 1][j + 2] = 20 + d;
                }
            }
        }

        for(i = m, j = n; i <= n; i++)
            if(dp[i][j]) break;

        if(i > n) {
            cout << -1 << '\n';
        } else {
            string b;
            for(; i or j; i--) {
                b += dp[i][j] % 10 + '0';
                j -= dp[i][j] / 10;
            }
            R::reverse(b);
            while(b.size() > 1 and b.back() == '0') b.pop_back();
            R::reverse(b);
            cout << b << '\n';
        }
    }();

} // ~W