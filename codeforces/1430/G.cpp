/**
 🍪 the_hyp0cr1t3
 🍪 11.10.2020 17:43:29
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 18;
const int V = 100;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[--u][--v] = w;
    }

    vector<int> dp(1<<n, INF);
    vector<vector<int>> vals(n, vector<int>(1<<n, -1));
    dp[0] = 0;

    auto combine = [&](int msk, int j) {
        int l = -INF, r = INF;
        for(int i = 0; i < n; i++) {
            if(msk>>i&1 and g[j][i]) {
                chmax(l, vals[i][msk] + 1);
            } else if(msk>>i&1 and g[i][j]) {
                chmin(r, vals[i][msk] - 1);
            }
        }
        if(l > r) return make_pair(-1, -1);
        if(l == -INF and r == INF) return make_pair(0, V);

        int Lw = 0, Rw = 0, total = 0, x;
        for(int i = 0; i < n; i++) {
            if(msk>>i&1 and g[j][i]) {
                Lw += g[j][i];
            } else if(msk>>i&1 and g[i][j]) {
                Rw += g[i][j];
            }
        } x = Lw > Rw? l : r;

        for(int i = 0; i < n; i++) {
            if(msk>>i&1 and g[j][i]) {
                total += g[j][i] * abs(vals[i][msk] - x);
            } else if(msk>>i&1 and g[i][j]) {
                total += g[i][j] * abs(vals[i][msk] - x);
            }
        } return make_pair(total, x);
    };

    for(int i = 0; i < n; i++) {
        dp[1<<i] = 0;
        vals[i][1<<i] = V;
    }

    for(int msk = 1; msk < 1<<n; msk++) {
        for(int i = 0; i < n; i++) {
            if(msk>>i&1) continue;
            auto [total, val] = combine(msk, i);
            if(total == -1 or !chmin(dp[msk|1<<i], total + dp[msk]))
                continue;            
            for(int j = 0; j < n; j++)
                vals[j][msk|1<<i] = vals[j][msk];
            vals[i][msk|1<<i] = val;
        }
    }

    for(int i = 0; i < n; i++)
        cout << vals[i][(1<<n)-1] << " \n"[i == n-1];
}