/**
 🍪 the_hyp0cr1t3
 🍪 08.08.2021 17:48:29
**/
#ifdef W
    #include "k_II.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const array dx{1, 0, -1, 0};
const array dy{0, 1, 0, -1};

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(auto& x: a) cin >> x;

    auto valid = [&](int x, int y, bool good) {
        return 0 <= x and x < n and 0 <= y and y < m and (good? a[x][y] == '.' : true);
    };

    struct state {
        int x, y; int64_t dist;
        state(int x, int y, int64_t dist): x(x), y(y), dist(dist) {}
        bool operator<(const state& o) const {
            return dist > o.dist;
        }
    };


    vector<vector<int>> d(n, vector<int>(m, INF));
    priority_queue<state> pq;
    pq.emplace(0, 0, d[0][0] = 0);
    while(!pq.empty()) {
        state top = pq.top(); pq.pop();
        int curx = top.x, cury = top.y;
        if(top.dist > d[curx][cury]) continue;

        for(int z = 0; z < 4; z++) {
            int nx = curx + dx[z];
            int ny = cury + dy[z];

            if(valid(nx, ny, true) and chmin(d[nx][ny], d[curx][cury]))
                pq.emplace(nx, ny, d[nx][ny]);

            for(int delx = -1; delx <= 1; delx++)
                for(int dely = -1; dely <= 1; dely++)
                    if(valid(nx + delx, ny + dely, false) and chmin(d[nx + delx][ny + dely], d[curx][cury] + 1))
                        pq.emplace(nx + delx, ny + dely, d[nx + delx][ny + dely]);
        }
    }

    cout << d[n-1][m-1];
} // ~W