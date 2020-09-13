/**
 🍪 the_hyp0cr1t3
 🍪 13.09.2020 22:35:31
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const array dx{0, -1, 0, 1};
const array dy{1, 0, -1, 0};

const int N = 2000;
int vis[N][N];

int32_t main() {
    aylmao
    int i, n, m, stx, sty, L, R, ans = 0;
    cin >> n >> m >> stx >> sty >> L >> R;
    stx--; sty--;
    vector<string> a(n);
    for(auto& x: a) cin >> x;

    auto valid = [&](int x, int y) {
        return x > -1 and y > -1 and x < n and y < m and a[x][y] == '.';
    };

    deque<tuple<int, int, int, int>> q;
    q.pb(stx, sty, L, R); vis[stx][sty] = 1;
    while(!q.empty()) {
        auto [x, y, l, r] = q.front(); q.pop_front();
        ans++;
        for(i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!valid(nx, ny) or vis[nx][ny]) continue;
            if(i == 0) {
                if(r) q.pb(nx, ny, l, r-1), vis[nx][ny] = 1;
            } else if(i == 2) {
                if(l) q.pb(nx, ny, l-1, r), vis[nx][ny] = 1;
            } else {
                q.emplace_front(nx, ny, l, r), vis[nx][ny] = 1;
            }
        }
    }

    cout << ans << '\n';
}