/**
 🍪 the_hyp0cr1t3
 🍪 18.12.2021 21:10:07
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
    while(tests--) []() {
        int w, h, i, j, k; int64_t ans = 0;
        cin >> w >> h;

        for(i = 0; i < 2; i++) {
            cin >> k;
            int mn = 1e9, mx = -1, x;
            for(j = 0; j < k; j++) {
                cin >> x;
                mn = min(mn, x);
                mx = max(mx, x);
            }
            ans = max<int64_t>(ans, 1LL * (mx - mn) * h);
        }

        for(i = 0; i < 2; i++) {
            cin >> k;
            int mn = 1e9, mx = -1, x;
            for(j = 0; j < k; j++) {
                cin >> x;
                mn = min(mn, x);
                mx = max(mx, x);
            }
            ans = max<int64_t>(ans, 1LL * (mx - mn) * w);
        }

        cout << ans << '\n';
    }();

} // ~W