/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 20:05:49
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
        int i, j, n, m, r, c;
        cin >> n >> m >> r >> c;
        vector<string> a(n);
        for(auto& x: a) cin >> x;

        int ans = 3;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(a[i][j] == 'W') continue;
                if(i + 1 == r and j + 1 == c)
                    ans = 0;
                if(i + 1 == r or j + 1 == c)
                    ans = min(ans, 1);
                ans = min(ans, 2);
            }
        }

        cout << (ans > 2? -1 : ans) << '\n';
    }();

} // ~W