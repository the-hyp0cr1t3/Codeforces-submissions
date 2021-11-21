/**
 🍪 the_hyp0cr1t3
 🍪 21.11.2021 14:46:05
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) []() {
        int i, j, k, n, d, ans = 0;
        cin >> n >> d;
        vector<int> a(n), visi(n), visj(n);
        for(auto& x: a) cin >> x;

        for(k = 0; k < d; k++) {
            int cnt = 0;
            for(i = j = k; !visi[i]; i = j) {
                while(!visi[i] and !a[i]) visi[i]++, i = (i + d) % n;
                for(cnt = 0, j = i; visj[j] < 2 and a[j]; j = (j + d) % n)
                    cnt++, visj[j]++;
                visi[i]++;
                if(i == j and cnt)
                    return cout << -1 << '\n', 0;
                ans = max(ans, cnt);
            }
        }

        cout << ans << '\n';
        return 0;
    }();

} // ~W