/**
 🍪 the_hyp0cr1t3
 🍪 03.01.2022 20:07:11
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
        int i, n, k;
        cin >> n >> k;
        vector<string> ans(n, string(n, '.'));
        for(i = 0; k and i < n; i += 2, k--)
            ans[i][i] = 'R';

        if(k)
            cout << -1 << '\n', 0;
        else
            for(auto& x: ans) cout << x << '\n';
    }();

} // ~W