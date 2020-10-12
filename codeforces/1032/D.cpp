/**
 🍪 the_hyp0cr1t3
 🍪 13.10.2020 00:54:41
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
    double x, y;
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    double a, b, c;
    Point start, end;
    cin >> a >> b >> c;
    cin >> start.x >> start.y;
    cin >> end.x >> end.y;

    array<Point, 2> from, to;

    from[0].x = start.x;
    from[0].y = -(a*start.x + c)/b;

    from[1].y = start.y;
    from[1].x = -(b*start.y + c)/a;

    to[0].x = end.x;
    to[0].y = -(a*end.x + c)/b;
    
    to[1].y = end.y;
    to[1].x = -(b*end.y + c)/a;

    auto distance = [&](const Point& p1, const Point& p2) {
        return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
    };

    auto manhattan = [&](const Point& p1, const Point& p2) {
        return abs(p1.x-p2.x) + abs(p1.y-p2.y);
    };

    double ans = manhattan(start, end);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            double dist = 0;
            dist += manhattan(start, from[i]);
            dist += distance(from[i], to[j]);
            dist += manhattan(to[j], end);
            ans = min(ans, dist);
        }
    }

    cout.precision(9);
    cout << ans << '\n';
}