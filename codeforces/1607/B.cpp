/**
 🍪 the_hyp0cr1t3
 🍪 04.11.2021 21:27:21
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    namespace r = ranges; namespace v = views;

    int tests; cin >> tests;
    while(tests--) []() {
        int64_t x, n;
        cin >> x >> n;
        cout << x + (x & 1? -1 : 1)
                    * (n % 4 == 0? 0
                        : n % 4 == 1? -n
                            : n % 4 == 2? 1 : 1 + n) << '\n';
    }();

} // ~W