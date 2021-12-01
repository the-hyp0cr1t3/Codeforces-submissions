/**
 🍪 the_hyp0cr1t3
 🍪 01.12.2021 20:15:35
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
        int i, n;
        cin >> n;
        vector<int> a(n);
        for(auto& x: a) cin >> x;
        r::sort(a);
        for(i = 1; i <= n / 2; i++)
            cout << a[i] << ' ' << a[0] << '\n';
    }();

} // ~W