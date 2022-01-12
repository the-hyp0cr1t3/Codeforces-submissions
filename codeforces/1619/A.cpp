/**
 🍪 the_hyp0cr1t3
 🍪 12.01.2022 15:24:47
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
    while(tests--) [&]() {
        int i, n; string s; bool bad = false;
        cin >> s; n = s.size();
        for(i = 0; i < n / 2; i++)
            bad |= s[i] ^ s[i + n / 2];
        bad |= n & 1;
        cout << (bad? "nO" : "yEs") << '\n';
    }();

} // ~W