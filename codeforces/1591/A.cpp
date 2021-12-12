/**
 🍪 the_hyp0cr1t3
 🍪 12.12.2021 20:45:54
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
        int i, n, ans = 1;
        cin >> n;
        vector<int> a(n);
        for(auto& x: a) cin >> x;

        for(i = 0; i < n; i++) {
            if(i > 0 and !a[i - 1] and !a[i])
                return cout << -1 << '\n', 0;
            ans += a[i] + (i > 0 and a[i] and a[i - 1]? 4 : 0);
        }

        return cout << ans << '\n', 0;
    }();

} // ~W