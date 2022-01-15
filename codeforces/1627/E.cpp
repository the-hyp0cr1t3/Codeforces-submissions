/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 21:12:12
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

const int64_t NINF = -1e18;
struct ladder {
    int a, b, c, d, h;
    int64_t dp;
    ladder(int a, int b, int c, int d, int h, int64_t dp = NINF)
        : a(a), b(b), c(c), d(d), h(h), dp(dp) {}
    bool operator<(const ladder& o) const {
        return b < o.b;
    }
    friend ostream& operator<<(ostream& os, const ladder& o) {
        os << "(" << o.a << ", " << o.b << ")(" << o.c << ", " << o.d << ") " << o.h << ": " << o.dp; return os;
    }
};

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, n, m, k;
        cin >> n >> m >> k;
        vector<int64_t> xi(n);
        for(auto& x: xi) cin >> x;

        vector<vector<ladder>> ladders(n + 1);
        while(k--) {
            int a, b, c, d, h;
            cin >> a >> b >> c >> d >> h;
            ladders[a].emplace_back(a, b, c, d, h);
        }
        ladders[n].emplace_back(n, m, -1, -1, 0);
        ladders[0].emplace_back(0, 1, 1, 1, 0, 0);

        for(i = 1; i < n; i++)
            sort(ladders[i].begin(), ladders[i].end());

        for(i = 0; i < n; i++) {
            for(j = 1; j < ladders[i].size(); j++)
                if(ladders[i][j - 1].dp > NINF)
                    ladders[i][j].dp = max(ladders[i][j].dp, ladders[i][j - 1].dp - xi[i - 1] * abs(ladders[i][j - 1].b - ladders[i][j].b));
            for(j = int(ladders[i].size()) - 2; j >= 0; j--)
                if(ladders[i][j + 1].dp > NINF)
                    ladders[i][j].dp = max(ladders[i][j].dp, ladders[i][j + 1].dp - xi[i - 1] * abs(ladders[i][j + 1].b - ladders[i][j].b));
            for(auto& l: ladders[i]) {
                // ps(l);
                if(ladders[l.c].empty() or l.dp == NINF) continue;
                int lo = 0, hi = ladders[l.c].size() - 1;
                while(lo <= hi) {
                    int mid = lo + hi >> 1;
                    if(ladders[l.c][mid].b <= l.d) lo = mid + 1;
                    else hi = mid - 1;
                }
                if(0 <= lo and lo < ladders[l.c].size())
                    ladders[l.c][lo].dp = max(ladders[l.c][lo].dp, l.dp - xi[l.c - 1] * abs(l.d - ladders[l.c][lo].b) + l.h);
                if(0 <= hi and hi < ladders[l.c].size())
                    ladders[l.c][hi].dp = max(ladders[l.c][hi].dp, l.dp - xi[l.c - 1] * abs(l.d - ladders[l.c][hi].b) + l.h);
            }
        }

        // ps(ladders[n][0]);

        if(ladders[n][0].dp == NINF)
            cout << "NO ESCAPE" << '\n';
        else
            cout << -ladders[n][0].dp << '\n';

    }();

} // ~W