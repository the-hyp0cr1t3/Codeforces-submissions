/**
 🍪 the_hyp0cr1t3
 🍪 12.01.2022 17:40:58
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
        int i, n;
        cin >> n;
        map<int, vector<int>> occ;
        for(i = 0; i < n; i++) {
            int x; cin >> x;
            occ[x].push_back(i);
        }

        int ans = -1;
        for(auto& [k, v]: occ)
            for(i = 0; i + 1 < v.size(); i++)
                ans = max(ans, v[i] + n - v[i + 1]);

        cout << ans << '\n';
    }();

} // ~W