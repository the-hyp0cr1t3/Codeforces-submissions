/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 20:13:17
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
        cin >> n >> m;
        vector<int> a;
        a.reserve(n * m);
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                a.push_back(max({i + j, n - 1 - i + j, i + m - 1 - j, n - 1 - i + m - 1 - j}));
        R::sort(a);
        for(auto& x: a) cout << x << ' ';
        cout << '\n';

    }();

} // ~W