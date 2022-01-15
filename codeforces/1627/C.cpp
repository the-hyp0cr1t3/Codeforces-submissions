/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 20:18:05
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
        int i, n, o = 2;
        cin >> n;
        vector<vector<pair<int, int>>> g(n);
        for(i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            g[--u].emplace_back(--v, i);
            g[v].emplace_back(u, i);
        }

        int v = -1, prv = -1;
        for(i = 0; i < n; i++) {
            if(g[i].size() > 2) return cout << -1 << '\n', 0;
            if(g[i].size() == 1) v = i;
        }

        vector<int> ans(n - 1);
        for(i = 0; i < n - 1; i++) {
            for(auto& [u, idx]: g[v]) {
                if(u ^ prv) {
                    ans[idx] = o ^= 1;
                    prv = exchange(v, u);
                    break;
                }
            }
        }

        for(auto& x: ans) cout << x << ' ';
        cout << '\n';
        return 0;
    }();

} // ~W