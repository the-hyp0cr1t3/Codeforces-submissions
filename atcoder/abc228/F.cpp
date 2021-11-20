/**
 🍪 the_hyp0cr1t3
 🍪 20.11.2021 18:19:09
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

    int i, j, n, m, a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;
    c = min(c, a); d = min(d, b);

    vector<vector<int64_t>> A(n + 1, vector<int64_t>(m + 1));
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> A[i][j];
            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
        }
    }

    auto get = [&](int x2, int y2, int x1, int y1) {
        return A[x2][y2] - A[x1][y2] - A[x2][y1] + A[x1][y1];
    };

    vector<vector<int64_t>> B(n + 1, vector<int64_t>(m + 1));
    for(j = d; j <= m; j++) {
        deque<array<int64_t, 2>> q;
        for(i = c; i <= n; i++) {
            int64_t x = get(i, j, i - c, j - d);
            while(!q.empty() and q.back()[0] <= x)
                q.pop_back();
            q.push_back({x, i});
            while(!q.empty() and q.front()[1] < i - a + c)
                q.pop_front();
            B[i][j] = q.front()[0];
        }
    }

    int64_t ans = 0;
    for(i = a; i <= n; i++) {
        deque<array<int64_t, 2>> q;
        for(j = d; j <= m; j++) {
            int64_t x = B[i][j];
            while(!q.empty() and q.back()[0] <= x)
                q.pop_back();
            q.push_back({x, j});
            while(q.front()[1] < j - b + d)
                q.pop_front();
            if(j >= b)
                ans = max(ans, get(i, j, i - a, j - b) - q.front()[0]);
        }
    }

    cout << ans;
} // ~W