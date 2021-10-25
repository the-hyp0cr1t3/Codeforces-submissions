/**
 🍪 the_hyp0cr1t3
 🍪 25.10.2021 21:47:05
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
        string s;
        cin >> s;
        auto it = r::min_element(s);
        cout << *it << ' ';
        s.erase(it);
        cout << s << '\n';
    }();

} // ~W