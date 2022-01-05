/**
 🍪 the_hyp0cr1t3
 🍪 05.01.2022 16:44:32
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
        int i, j, n;
        cin >> n;

        vector a(2 * n, vector<int>(2 * n));
        for(i = 0; i < 2 * n; i++)
            for(j = 0; j < 2 * n; j++)
                cin >> a[i][j];

        int64_t base = 0; int clear = 2e9;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                base += a[i][j] + a[i + n][j + n];

        for(int x: { 0, n - 1 })
            for(int y: { n, 2 * n - 1 })
                clear = min({ clear, a[x][y], a[y][x] });

        cout << base + clear << '\n';
    }();

} // ~W