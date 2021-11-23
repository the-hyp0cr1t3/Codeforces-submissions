/**
 🍪 the_hyp0cr1t3
 🍪 23.11.2021 20:06:06
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
        int i, n, m;
        cin >> n >> m;
        cout << (1 + (min(n, m) > 1) - (max(n, m) == 1)) << '\n';

    }();

} // ~W