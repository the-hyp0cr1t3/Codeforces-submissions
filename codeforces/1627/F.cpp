/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 22:03:00
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
    const pair<int, int> dirs[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    constexpr int64_t b1 = 696;
    constexpr int64_t b2 = b1 * b1;
    constexpr int64_t b3 = b2 * b1;

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, n, k, ans = 1e9;
        cin >> n >> k;
        map<int64_t, int> bad;
        for(i = 0; i < n; i++) {
            int p, q, r, s;
            cin >> p >> q >> r >> s;
            if(p == r)
                bad[(p - 1) * b3 + min(q, s) * b2 + p * b1 + min(q, s)]++;
            else
                bad[min(p, r) * b3 + (q - 1) * b2 + min(p, r) * b1 + q]++;
        }

        auto get = [&](int p, int q, int r, int s) {
            return bad[p * b3 + q * b2 + r * b1 + s]
                    + bad[(k - r) * b3 + (k - s) * b2 + (k - p) * b1 + (k - q)];
        };

        struct state {
            int i, j; int64_t dist;
            state(int i, int j, int64_t dist): i(i), j(j), dist(dist) {}
            bool operator<(const state& o) const {
                return dist > o.dist;
            }
        };

        vector d(k + 1, vector<int>(k + 1, 1e9));
        priority_queue<state> pq;
        for(i = 1; i < k; i++) {
            pq.emplace(i, 0, d[i][0] = 0);
            pq.emplace(0, i, d[0][i] = 0);
            pq.emplace(i, k, d[i][k] = 0);
            pq.emplace(k, i, d[k][i] = 0);
        }

        while(!pq.empty()) {
            state top = pq.top(); pq.pop();
            if(top.dist > d[top.i][top.j]) continue;
            for(auto [dx, dy]: dirs) {
                int x = top.i + dx;
                int y = top.j + dy;
                if(0 < x and x < k and 0 < y and y < k
                    and chmin(d[x][y], top.dist + get(min(top.i, x), min(top.j, y), max(top.i, x), max(top.j, y))))
                        pq.emplace(x, y, d[x][y]);
            }
        }

        cout << n - d[k / 2][k / 2] << '\n';
    }();

} // ~W