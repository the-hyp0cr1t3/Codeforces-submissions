/**
 🍪 the_hyp0cr1t3
 🍪 18.12.2021 21:07:45
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
        string s;
        cin >> s;
        cout << (R::count(s, 'N') == 1 and s.size() > 1? "nO" : "yEs") << '\n';
    }();

} // ~W