/**
 🍪 the_hyp0cr1t3
 🍪 14.11.2021 11:40:17
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
    const int64_t N = 1e9 + 5;

    int tests; cin >> tests;
    while(tests--) [&]() {
        int n;
        cin >> n;

        auto query = [](int l, int r) {
            cout << "? " << l << ' ' << r << endl;
            int64_t x; cin >> x;
            assert(x != -1);
            return x;
        };

        int lo = 1, hi = n;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if(query(1, mid)) hi = mid - 1;
            else lo = mid + 1;
        }

        int i = hi;
        int j = query(i, n) - query(i + 1, n) + i + 1;
        int k = query(j, n) - query(j + 1, n) + j;

        cout << "! " << i << ' ' << j << ' ' << k << endl;
    }();

} // ~W