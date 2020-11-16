/**
 🍪 the_hyp0cr1t3
 🍪 16.11.2020 19:18:56
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

const array dx{1, 0, -1, 0};
const array dy{0, 1, 0, -1};
const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 1000 + 5;
bitset<N> a[N], ok[N];
int dp[4][N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, k, n, m; char c;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            cin >> c, a[i][j] = c == '*';

    for(i = n; i; i--)
        for(j = 1; j <= m; j++)
            if(a[i][j]) dp[0][i][j] = dp[0][i+1][j] + 1;

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i][j]) dp[2][i][j] = dp[2][i-1][j] + 1;

    for(j = m; j; j--)
        for(i = 1; i <= n; i++)
            if(a[i][j]) dp[1][i][j] = dp[1][i][j+1] + 1;

    for(j = 1; j <= m; j++)
        for(i = 1; i <= n; i++)
            if(a[i][j]) dp[3][i][j] = dp[3][i][j-1] + 1;

    vector<tuple<int, int, int>> ans;
    ans.reserve(n*m);
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            int r = INF;
            for(k = 0; k < 4; k++)
                r = min(r, dp[k][i][j]);
            if(--r <= 0) continue;
            ans.pb(i, j, r);
            for(k = 0; k <= r; k++) {
                for(int z = 0; z < 4; z++) {
                    int x = i + k * dx[z];
                    int y = j + k * dy[z];
                    if(x and x <= n and y and y <= m)
                        ok[x][y] = 1;
                }
            }
        }
    }

    for(i = 1; i <= n; i++)
        if(a[i] != ok[i]) return cout << -1 << '\n', 0;

    cout << sz(ans) << '\n';
    for(auto [x, y, r]: ans)
        cout << x << ' ' << y << ' ' << r << '\n';
} // ~W