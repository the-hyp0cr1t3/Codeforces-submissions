/**
 🍪 the_hyp0cr1t3
 🍪 03.01.2022 21:01:20
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
    const array<pair<int, int>, 4> dirs{pair{-1, 0}, pair{0, -1}, pair{1, 0}, pair{0, 1}};

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, n; int64_t base = 0, ans = 1e18;
        cin >> n;
        vector<vector<int>> a(2* n, vector<int>(2 * n));
        for(auto& v: a) for(auto& x: v) cin >> x;

        for(i = 0; i < 2 * n; i++) {
            for(j = 0; j < 2 * n; j++) {
                if(i < n and j < n or i >= n and j >= n)
                    base += a[i][j];
                else {
                    int f = 0;
                    for(auto [dx, dy]: dirs) {
                        int ni = (i + dx + 2 * n) % (2 * n);
                        int nj = (j + dy + 2 * n) % (2 * n);
                        if(ni < n and nj < n)
                            f |= 1;
                        if(ni >= n and nj >= n)
                            f |= 2;
                    }
                    if(f == 3) ans = min<int64_t>(ans, a[i][j]);
                }
            }
        }

        auto Try = [&](vector<int> v) {
            int m = v.size();
            int64_t sum = accumulate(v.begin(), v.begin() + n, 0LL);
            for(i = 0; i < m; i++) {
                ans = min(ans, sum);
                sum -= v[i];
                sum += v[(i + n) % m];
            }
        };

        {
            vector<int> v; v.reserve(2 * n);
            for(i = 0; i < n; i++)
                v.push_back(a[i][n]);
            for(; i < 2 * n; i++)
                v.push_back(a[i][n - 1]);
            Try(v);
        }

        {
            vector<int> v; v.reserve(2 * n);
            for(i = 0; i < n; i++)
                v.push_back(a[n][i]);
            for(; i < 2 * n; i++)
                v.push_back(a[n - 1][i]);
            Try(v);
        }

        {
            vector<int> v; v.reserve(2 * n);
            for(i = 0; i < n; i++)
                v.push_back(a[i][2 * n - 1]);
            for(; i < 2 * n; i++)
                v.push_back(a[i][0]);
            Try(v);
        }

        {
            vector<int> v; v.reserve(2 * n);
            for(i = 0; i < n; i++)
                v.push_back(a[2 * n - 1][i]);
            for(; i < 2 * n; i++)
                v.push_back(a[0][i]);
            Try(v);
        }

        cout << base + ans << '\n';
    }();

} // ~W
