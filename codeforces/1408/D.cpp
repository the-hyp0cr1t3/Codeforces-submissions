/**
 🍪 the_hyp0cr1t3
 🍪 30.09.2020 21:19:33
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
const int N = 1e6 + 5;

struct point {
    int x, y;
    point() = default;
    point(int x, int y): x(x), y(y) {}
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, m, ans = INF;
    cin >> n >> m;
    vector<point> robbers, lights;
    robbers.reserve(n); lights.reserve(m);

    for(i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        robbers.pb(x, y);
    }
    for(i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        lights.pb(x, y);
    }

    vector<pair<point, point>> pairs;
    pairs.reserve(n*m);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            pairs.pb(robbers[i], lights[j]);

    sort(all(pairs), [](const auto& A, const auto& B) {
        return A.second.y - A.first.y > B.second.y - B.first.y;
    });

    vector<int> pref(n*m);
    pref[0] = pairs[0].second.x - pairs[0].first.x + 1;
    for(i = 1; i < n*m; i++)
        pref[i] = max(pref[i-1], pairs[i].second.x - pairs[i].first.x + 1);

    for(int dy = 0; dy < N; dy++) {
        int lo = 0, hi = n*m - 1, dx = 0;
        while(lo <= hi) {
            int m = lo + hi >> 1;
            if(dy > pairs[m].second.y - pairs[m].first.y) hi = m - 1;
            else lo = m + 1;
        } if(~hi) chmax(dx, pref[hi]);
        chmin(ans, dx + dy);
    } cout << ans << '\n';
}