/**
 🍪 the_hyp0cr1t3
 🍪 12.12.2021 20:50:14
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
    auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
    auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, n, cur = -1, ans = 0;
        cin >> n;
        vector<int> a(n);
        for(auto& x: a) cin >> x;

        for(i = n - 1; ~i; i--)
            ans += chmax(cur, a[i]);

        cout << ans - 1 << '\n';
    }();

} // ~W