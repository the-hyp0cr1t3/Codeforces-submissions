/**
 🍪 the_hyp0cr1t3
 🍪 08.12.2021 01:42:11
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
        int n, have = 0, ans = 0;
        cin >> n;
        while(n--) {
            int x; cin >> x;
            int take = max(0, x - ++have);
            ans += take; have += take;
        }
        cout << ans << '\n';
    }();

} // ~W