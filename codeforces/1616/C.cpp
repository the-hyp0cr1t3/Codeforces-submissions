/**
 🍪 the_hyp0cr1t3
 🍪 29.12.2021 21:27:47
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
        int i, j, n, ans = 1e9;
        cin >> n;
        vector<int> a(n);
        for(auto& x: a)  cin >> x;

        if(n == 1) ans = 0;

        for(auto _: { 0, 1 }) {
            for(j = 0; j < n; j++) {
                map<double, int> cnt;
                for(i = 0; i < n; i++) {
                    if(i < j) {
                        cnt[1.0 * (a[j] - a[i]) / (j - i)]++;
                    } else if(i > j) {
                        cnt[1.0 * (a[i] - a[j]) / (i - j)]++;
                    }
                }
                for(auto& [k, v]: cnt)
                    ans = min(ans, n - 1 - v);
            }

            R::reverse(a);
        }

        cout << ans << '\n';
    }();

} // ~W