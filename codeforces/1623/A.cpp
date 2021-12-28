/**
 🍪 the_hyp0cr1t3
 🍪 28.12.2021 19:09:26
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
        int i, j, n, m, ex, ey, ans = -1, dx = 1, dy = 1;
        cin >> n >> m >> i >> j >> ex >> ey;

       while(true) {
            ans++;
            if(i == ex or j == ey)
                return cout << ans << '\n', 0;
            i += dx, j += dy;
            if(i == n + 1) i = n - 1, dx = -1;
            if(j == m + 1) j = m - 1, dy = -1;
            if(i == 0) i = 2, dx = 1;
            if(j == 0) j = 2, dy = 1;
        }

        assert(false);
        return 0;
    }();

} // ~W