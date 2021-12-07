/**
 🍪 the_hyp0cr1t3
 🍪 08.12.2021 01:46:41
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

        cout << (~n & 1 or R::adjacent_find(a, greater_equal{}) != a.end()? "yEs" : "nO") << '\n';
    }();

} // ~W