/**
 🍪 the_hyp0cr1t3
 🍪 08.12.2021 16:23:32
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
    const int N = 25;

    int tests; cin >> tests;
    while(tests--) [N]() {
        int i, j, n;
        cin >> n;
        vector<int> a(n);
        for(auto& x: a) cin >> x;

        for(i = 1; i <= min(n, N); i++) {
            bool ok = false;
            for(j = 2; j <= i + 1; j++)
                ok |= a[i - 1] % j;
            if(!ok)
                return cout << "nO" << '\n', 0;
        }

        return cout << "yEs" << '\n', 0;
    }();

} // ~W