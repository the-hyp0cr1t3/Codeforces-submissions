/**
 🍪 the_hyp0cr1t3
 🍪 04.10.2020 23:01:11
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
#define int int64_t
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 1e5 + 5;
int x[N], y[N], d[N], posx[N], posy[N], vis[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, ex, ey, ans = DESPACITO;
    cin >> n >> n;
    cin >> x[0] >> y[0] >> ex >> ey;
    vector<int> xpoints(n+1), ypoints(n+1);
    iota(all(xpoints), 0); iota(all(ypoints), 0);

    for(i = 1; i <= n; i++)
        cin >> x[i] >> y[i], d[i] = DESPACITO;

    sort(all(xpoints), [&](const auto& A, const auto& B) { 
        return x[A] < x[B];
    });
    sort(all(ypoints), [&](const auto& A, const auto& B) { 
        return y[A] < y[B];
    });

    for(i = 0; i <= n; i++)
        posx[xpoints[i]] = i;
    for(i = 0; i <= n; i++)
        posy[ypoints[i]] = i;

    priority_queue<pair<int, int>> pq;
    d[0] = 0;
    for(i = 0; i <= n; i++)
        pq.push({-d[i], i});
    while(!pq.empty()) {
        auto [tmp, v] = pq.top(); pq.pop();
        if(vis[v]++) continue;
        tmp = -tmp;
        int res = d[v] + abs(ex-x[v]) + abs(ey-y[v]);
        chmin(ans, res);
        int xi = posx[v], yi = posy[v];
        
        if(xi > 0) {
            int newpoint = xpoints[xi-1];
            if(chmin(d[newpoint], d[v] + x[v] - x[xpoints[xi-1]]))
                pq.push({-d[newpoint], newpoint});
        }
        if(xi < n) {
            int newpoint = xpoints[xi+1];
            if(chmin(d[newpoint], d[v] + x[xpoints[xi+1]] - x[v]))
                pq.push({-d[newpoint], newpoint});
        }
        if(yi > 0) {
            int newpoint = ypoints[yi-1];
            if(chmin(d[newpoint], d[v] + y[v] - y[ypoints[yi-1]]))
                pq.push({-d[newpoint], newpoint});
        }
        if(yi < n) {
            int newpoint = ypoints[yi+1];
            if(chmin(d[newpoint], d[v] + y[ypoints[yi+1]] - y[v]))
                pq.push({-d[newpoint], newpoint});
        }
    }

    cout << ans << '\n';   
}