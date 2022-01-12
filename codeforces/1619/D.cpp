/**
 🍪 the_hyp0cr1t3
 🍪 12.01.2022 16:06:13
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
        int i, j, n, m;
        cin >> m >> n;
        vector a(m, vector<int>(n));
        for(auto& v: a) for(auto& x: v) cin >> x;

        auto check = [&](int x) {
            bool many = false, none = false;
            vector<int> rows(n);
            for(i = 0; i < m; i++) {
                int cnt = 0;
                for(j = 0; j < n; j++)
                    if(a[i][j] >= x) cnt++, rows[j]++;
                many |= cnt > 1 or n > m;
            }
            return many and *R::min_element(rows);
        };

        int lo = 0, hi = 1e9;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if(check(mid)) lo = mid + 1;
            else hi = mid - 1;
        }

        cout << hi << '\n';
    }();

} // ~W