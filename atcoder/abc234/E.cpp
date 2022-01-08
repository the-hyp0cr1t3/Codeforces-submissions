/**
 🍪 the_hyp0cr1t3
 🍪 08.01.2022 17:44:21
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

    int i; int64_t n, ans = 2e18;
    cin >> n;

    for(int d = -9; d < 10; d++) {
        for(int j = 1; j < 10; j++) {
            int64_t x = 0;
            for(i = j; x < n; i += d) {
                if(i < 0 or i >= 10) break;
                x = x * 10 + i;
            }
            if(x >= n) ans = min(ans, x);
        }
    }

    cout << ans;
} // ~W