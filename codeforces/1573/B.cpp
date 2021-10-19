/**
 🍪 the_hyp0cr1t3
 🍪 19.10.2021 19:50:14
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) []() {
        int i, n, ans = 1e9;
        cin >> n;
        vector<pair<int, int>> a(n);
        for(i = 0; auto& [x, y]: a) cin >> x, y = i++;
        ranges::sort(a);

        vector<int> b(n);
        for(auto& x: b) cin >> x;

        for(i = 0; auto& [x, y]: a) {
            while(b[i] < x) i++;
            ans = min(ans, y + i);
        }

        cout << ans << '\n';

    }();

} // ~W