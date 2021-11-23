/**
 🍪 the_hyp0cr1t3
 🍪 23.11.2021 21:57:04
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
        vector<int> a(n), b(n);
        for(i = 0; i < n; i++)
            cin >> a[i] >> b[i];

        auto check = [&](int ans) {
            for(i = j = 0; i < n and j < ans; i++) {
                if(b[i] >= j and a[i] >= ans - j - 1)
                    j++;
            }
            return j == ans;
        };

        int lo = 1, hi = n;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if(check(mid)) lo = mid + 1;
            else hi = mid - 1;
        }

        cout << hi << '\n';
    }();

} // ~W