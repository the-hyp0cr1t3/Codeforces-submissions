/**
 🍪 the_hyp0cr1t3
 🍪 28.12.2021 19:37:59
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
        int i, n;
        cin >> n;
        vector<int64_t> a(n);
        for(auto& x: a) cin >> x;

        auto check = [&](int64_t x) {
            vector<int64_t> surplus(n);
            for(i = n - 1; i >= 0; i--) {
                if(a[i] + surplus[i] < x) return false;
                int64_t d = min(a[i], a[i] + surplus[i] - x) / 3;
                if(i >= 2) {
                    surplus[i - 1] += d;
                    surplus[i - 2] += 2 * d;
                }
            }
            return true;
        };

        int64_t lo = 0, hi = a.back();
        while(lo <= hi) {
            int64_t mid = lo + hi >> 1;
            if(check(mid)) lo = mid + 1;
            else hi = mid - 1;
        }

        cout << hi << '\n';
    }();

} // ~W