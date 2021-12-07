/**
 🍪 the_hyp0cr1t3
 🍪 07.12.2021 20:12:07
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
        int i, n, q; string s;
        cin >> s >> q;
        n = s.size();
        s = '$' + s;
        vector<int> pref(n + 1);
        for(i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + (s[i] == '[' or s[i] == ']') * (i & 1? +1 : -1);

        while(q--) {
            int l, r; cin >> l >> r;
            cout << abs(pref[r] - pref[l - 1]) << '\n';
        }
    }();

} // ~W