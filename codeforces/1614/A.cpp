/**
 🍪 the_hyp0cr1t3
 🍪 26.11.2021 16:45:31
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
        int i, n, l, r, k, ans = 0;
        cin >> n >> l >> r >> k;
        vector<int> a(n);
        for(auto& x: a) cin >> x;
        r::sort(a);
        for(i = 0; i < n; i++) {
            if(l <= a[i] and a[i] <= r and a[i] <= k)
                ans++, k -= a[i];
        }

        cout << ans << '\n';

    }();

} // ~W