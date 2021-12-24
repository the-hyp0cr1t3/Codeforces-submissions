/**
 🍪 the_hyp0cr1t3
 🍪 24.12.2021 20:05:35
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
        vector<int> a(n);
        for(auto& x: a) cin >> x;
        cout << !!(accumulate(a.begin(), a.end(), 0) % n) << '\n';

    }();

} // ~W