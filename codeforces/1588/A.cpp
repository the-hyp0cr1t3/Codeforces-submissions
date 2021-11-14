/**
 🍪 the_hyp0cr1t3
 🍪 14.11.2021 11:35:57
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
        vector<int> a(n), b(n);
        for(auto& x: a) cin >> x;
        for(auto& x: b) cin >> x;
        r::sort(a); r::sort(b);

        for(i = 0; i < n; i++)
            if(a[i] > b[i] or b[i] - a[i] > 1)
                return cout << "nO" << '\n', 0;
        return cout << "yEs" << '\n', 0;
    }();

} // ~W