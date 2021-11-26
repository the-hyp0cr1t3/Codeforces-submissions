/**
 🍪 the_hyp0cr1t3
 🍪 26.11.2021 16:49:09
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) []() {
        int i = 0, n; int64_t ans = 0;
        cin >> n;
        vector<pair<int, int>> a(n);
        for(auto& x: a)
            cin >> x.first, x.second = ++i;
        sort(a.rbegin(), a.rend());
        vector<int> pos(n + 1);
        for(i = 2; auto& [x, y]: a) {
            pos[y] = i / 2 * (i & 1? -1 : 1);
            ans += 2LL * x * abs(pos[y]);
            i++;
        }

        cout << ans << '\n';
        for(auto& x: pos) cout << x << ' ';
        cout << '\n';
    }();

} // ~W