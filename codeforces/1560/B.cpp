/**
 🍪 the_hyp0cr1t3
 🍪 14.10.2021 19:25:59
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
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b, --c;
        int n = abs(b - a) * 2;

        cout << (max({a, b, c}) < n? (c + n / 2) % n + 1 : -1) << '\n';

    }();

} // ~W