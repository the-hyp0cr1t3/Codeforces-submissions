/**
 🍪 the_hyp0cr1t3
 🍪 14.10.2021 19:31:32
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) []() {
        int i, n;
        cin >> n;

        int lo = 1, hi = 1e5;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if(1LL * mid * mid >= n) hi = mid - 1;
            else lo = mid + 1;
        }

        n -= hi * hi;

        if(n <= lo)
            cout << n << ' ' << lo << '\n';
        else
            cout << lo << ' ' << lo - (n - hi) + 1 << '\n';
    }();

} // ~W