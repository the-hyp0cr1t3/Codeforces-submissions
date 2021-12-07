/**
 🍪 the_hyp0cr1t3
 🍪 07.12.2021 21:46:43
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
    auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
    auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };
    const int INF = 2e9;

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, n, m;
        cin >> n >> m;
        string ans(n, 'R');
        vector<vector<int>> a(n, vector<int>(m + 1)), mxB, mnR, mnB, mxR;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++)
                cin >> a[i][j];
            a[i][m] = i;
        }

        sort(a.begin(), a.end(), [](const auto& A, const auto& B) {
            return A[0] < B[0];
        });

        auto bounds = [&](int x, int y) {
            return 0 <= x and x < n and 0 <= y and y < m;
        };

        mxB = mnR = mnB = mxR = a;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++)
                mxB[i][j] = max({
                    mxB[i][j],
                    (bounds(i - 1, j)? mxB[i - 1][j] : -INF),
                    (bounds(i, j - 1)? mxB[i][j - 1] : -INF)
                });
            for(j = m - 1; ~j; j--)
                mnB[i][j] = min({
                    mnB[i][j],
                    (bounds(i - 1, j)? mnB[i - 1][j] : INF),
                    (bounds(i, j + 1)? mnB[i][j + 1] : INF)
                });
        }
        for(i = n - 1; ~i; i--) {
            for(j = 0; j < m; j++)
                mnR[i][j] = min({
                    mnR[i][j],
                    (bounds(i + 1, j)? mnR[i + 1][j] : INF),
                    (bounds(i, j - 1)? mnR[i][j - 1] : INF)
                });
            for(j = m - 1; ~j; j--)
                mxR[i][j] = max({
                    mxR[i][j],
                    (bounds(i + 1, j)? mxR[i + 1][j] : -INF),
                    (bounds(i, j + 1)? mxR[i][j + 1] : -INF)
                });
        }

        for(i = 0; i + 1 < n; i++) {
            ans[a[i][m]] = 'B';
            int lo = 0, hi = m - 2;
            while(lo <= hi) {
                int mid = lo + hi >> 1;
                if(mxB[i][mid] < mnR[i + 1][mid])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }

            if(~hi and mnB[i][lo] > mxR[i + 1][lo])
                return cout << "yEs" << '\n' << ans << ' ' << lo << '\n', 0;
        }

        return cout << "nO" << '\n', 0;
    }();

} // ~W