/**
 🍪 the_hyp0cr1t3
 🍪 17.10.2020 14:23:27
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

struct Point {
    int x, y;
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n;
    array<array<Point, 2>, 3> a;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 2; j++)
            cin >> a[i][j].x >> a[i][j].y;

    auto intersect = [&](const array<Point, 2>& p, const array<Point, 2>& q) {
        int64_t X = max(0, min(p[1].x, q[1].x) - max(p[0].x, q[0].x));
        int64_t Y = max(0, min(p[1].y, q[1].y) - max(p[0].y, q[0].y));
        return X * Y;
    };

    auto ar = [&](const array<Point, 2>& p) {
        return 1ll * (p[1].x-p[0].x) * (p[1].y-p[0].y);
    };

    array<Point, 2> f = a[1], g = a[2];
    f[0].x = min(f[1].x, max(f[0].x, a[0][0].x));
    f[0].y = min(f[1].y, max(f[0].y, a[0][0].y));
    f[1].x = max(f[0].x, min(f[1].x, a[0][1].x));
    f[1].y = max(f[0].y, min(f[1].y, a[0][1].y));

    g[0].x = min(g[1].x, max(g[0].x, a[0][0].x));
    g[0].y = min(g[1].y, max(g[0].y, a[0][0].y));
    g[1].x = max(g[0].x, min(g[1].x, a[0][1].x));
    g[1].y = max(g[0].y, min(g[1].y, a[0][1].y));

    cout << (ar(a[0]) > intersect(a[0], a[1]) + intersect(a[0], a[2]) - intersect(f, g) ? "YES" : "NO") << '\n';
}