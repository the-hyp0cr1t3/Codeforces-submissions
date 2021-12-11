/**
 🍪 the_hyp0cr1t3
 🍪 11.12.2021 15:35:41
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
        for(i = 1; i <= n; i++)
            cout << i + 1 << " \n"[i == n];

    }();

} // ~W