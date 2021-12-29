/**
 🍪 the_hyp0cr1t3
 🍪 29.12.2021 21:05:34
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
        int i, n, ans = 0;
        cin >> n;
        map<int, int> cnt;
        while(n--) {
            int x; cin >> x;
            cnt[abs(x)]++;
        }

        for(auto& [k, v]: cnt)
            ans += min(1 + !!k, v);

        cout << ans << '\n';
    }();

} // ~W