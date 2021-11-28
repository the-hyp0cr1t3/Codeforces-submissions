/**
 🍪 the_hyp0cr1t3
 🍪 28.11.2021 20:06:04
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
        int i, j, n;
        cin >> n;
        vector<int64_t> a(n);
        for(auto& x: a) cin >> x;

        int64_t ans = accumulate(a.begin(), a.end(), 0LL);
        for(i = 0; i < n; i++) {
            auto b = a;
            for(j = 0; j < n; j++) {
                if(j == i) continue;
                while(b[j] % 2 == 0)
                    b[j] >>= 1, b[i] <<= 1;
            }
            ans = max<int64_t>(ans, accumulate(b.begin(), b.end(), 0LL));
        }

        cout << ans << '\n';
    }();

} // ~W