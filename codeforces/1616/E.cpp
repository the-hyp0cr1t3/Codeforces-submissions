/**
 🍪 the_hyp0cr1t3
 🍪 09.01.2022 17:03:57
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

template <class T, bool ONE = true>
struct BIT {
    int N; vector<T> bit;
    BIT() = default;
    BIT(int N): N(N), bit(N + 1) {}

    BIT(const vector<T>& a) : N(a.size()), bit(N + 1) {
        for(int i = 1; i <= N; i++) {
            bit[i] += a[i-1];
            if(i + (i & -i) <= N)
                bit[i + (i & -i)] += bit[i];
        }
    }

    T query(int i) {
        T res = 0;
        for(i += !ONE; i; i -= i & -i)
            res += bit[i];
        return res;
    }

    T query(int l, int r) {
        if(l > r) return T();
        return query(r) - query(l - 1);
    }

    void update(int i, T val) {
        for(i += !ONE; i <= N; i += i & -i)
            bit[i] += val;
    }
};

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int M = 26;

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, n; string s, t;
        cin >> n >> s >> t;

        if(s < t)
            return cout << 0 << '\n', 0;

        auto ss = s;
        R::sort(ss);
        if(ss >= t)
            return cout << -1 << '\n', 0;

        array<int, M> cur{};
        array<vector<int>, M> occ;
        array<BIT<int, 0>, M> bit;
        for(i = 0; i < n; i++)
            occ[s[i] - 'a'].push_back(i);
        for(j = 0; j < M; j++) {
            occ[j].push_back(n);
            bit[j] = BIT<int, 0>(occ[j].size());
        }

        int64_t ans = 1e18, base = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < t[i] - 'a'; j++)
                if(occ[j][cur[j]] < n)
                    ans = min(ans, base + occ[j][cur[j]] + bit[j].query(cur[j]) - i);
            if(occ[j][cur[j]] == n) break;
            int pos = occ[j][cur[j]] + bit[j].query(cur[j]);
            base += pos - i;
            cur[j]++;
            for(j = 0; j < M; j++) {
                if(j == t[i] - 'a') continue;
                int lo = cur[j], hi = occ[j].size() - 1;
                while(lo <= hi) {
                    int mid = lo + hi >> 1;
                    if(occ[j][mid] + bit[j].query(mid) >= pos) hi = mid - 1;
                    else lo = mid + 1;
                }
                bit[j].update(cur[j], +1);
                bit[j].update(lo, -1);
            }
        }

        cout << ans << '\n';
        return 0;
    }();

} // ~W