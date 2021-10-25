/**
 🍪 the_hyp0cr1t3
 🍪 26.10.2021 01:39:39
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    namespace r = ranges; namespace v = views;
    auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
    auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, n; string s;
        cin >> n >> s;

        vector<int> dp(n);
        for(i = 0; i < n; i++) {
            // s[i..n-1] # s[0..i-1]
            auto Z = [](const string& s) {
                int n = s.size();
                vector<int> z(n);
                for(int k = 1, l = 0, r = 0; k < n; ++k) {
                    if(k <= r)
                        z[k] = min(r - k + 1, z[k - l]);
                    while(k + z[k] < n and s[z[k]] == s[k + z[k]])
                        z[k]++;
                    if(k + z[k] - 1 > r)
                        l = k, r = k + z[k] - 1;
                } return z;
            }(s.substr(i) + '~' + s);

            dp[i] = n - i;
            for(j = 0; j < i; j++) {
                int z = Z[n - i + 1 + j];
                if(i + z < n and s[j + z] < s[i + z])
                    chmax(dp[i], dp[j] + n - i - z);
            }
        }

        cout << *r::max_element(dp) << '\n';
    }();

} // ~W