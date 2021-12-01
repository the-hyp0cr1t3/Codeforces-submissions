/**
 🍪 the_hyp0cr1t3
 🍪 01.12.2021 20:23:23
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
        int i, n; int64_t h;
        cin >> n >> h;
        vector<int64_t> a(n);
        for(auto& x: a) cin >> x;

        auto check = [&](int64_t x) {
            int64_t rem = h;
            for(i = 0; rem >= 0 and i < n; i++)
                rem -= i + 1 < n? min(x, a[i + 1] - a[i]) : x;
            return rem <= 0;
        };

        int64_t lo = 1, hi = h;
        while(lo <= hi) {
            int64_t mid = lo + hi >> 1;
            if(check(mid)) hi = mid - 1;
            else lo = mid + 1;
        }

        cout << lo << '\n';
    }();

} // ~W