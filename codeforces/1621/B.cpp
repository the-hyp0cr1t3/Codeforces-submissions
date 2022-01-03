/**
 🍪 the_hyp0cr1t3
 🍪 03.01.2022 20:11:07
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
    while(tests--) []() {
        int i, n, bestl = 0, bestr = 0, bestcl = 1e9, bestcr = 1e9;
        cin >> n;
        set<array<int, 3>> l, r, both;
        for(i = 1; i <= n; i++) {
            int li, ri, ci; cin >> li >> ri >> ci;
            l.insert({li, ci, i});
            r.insert({-ri, ci, i});
            int mn = (*l.begin())[0];
            int mx = -(*r.begin())[0];
            if(li == mn and ri == mx)
                both.insert({ci, li, ri});
            while(!both.empty()) {
                auto [c, lb, rb] = *both.begin();
                if(lb ^ mn or rb ^ mx) both.erase(both.begin());
                else break;
            }
            int64_t ans = both.empty()? 2e9 + 5 : (*both.begin())[0];
            for(int p = 0; auto [l1, c1, i1]: l) {
                if(p == 5 or l1 > mn) break;
                for(int q = 0; auto [r2, c2, i2]: r) {
                    r2 = -r2;
                    if(q == 5 or r2 < mx) break;
                    ans = min(ans, (int64_t)c1 + c2);
                    q++;
                }
                if(r.count({-mx, c1, i1}))
                    ans = min(ans, (int64_t)c1);
                p++;
            }

            cout << ans << '\n';
        }

    }();

} // ~W