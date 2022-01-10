/**
 🍪 the_hyp0cr1t3
 🍪 10.01.2022 02:50:49
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

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<string> s(n);
        for(auto& x: a) cin >> x;
        for(auto& x: s) {
            cin >> x;
            for(auto& c: x) c -= '0';
        }

        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);

        vector<int> ans;
        int64_t best = -1;
        for(int msk = 0; msk < 1 << n; msk++) {
            int64_t res = 0;
            vector<int> cnt(m), p(m);
            for(i = 0; i < n; i++) {
                int sgn = (msk >> i & 1? 1 : -1);
                res -= sgn * a[i];
                for(j = 0; j < m; j++)
                    cnt[j] += sgn * s[i][j];
            }

            R::sort(idx, [&cnt](int x, int y) { return cnt[x] < cnt[y]; });
            for(j = 0; j < m; j++) {
                p[idx[j]] = j + 1;
                res += 1LL * p[idx[j]] * cnt[idx[j]];
            }

            if(best < res)
                best = res, ans = p;
        }

        for(j = 0; j < m; j++)
            cout << ans[j] << " \n"[j + 1 == m];
    }();

} // ~W