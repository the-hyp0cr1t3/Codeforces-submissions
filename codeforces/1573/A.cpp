/**
 🍪 the_hyp0cr1t3
 🍪 19.10.2021 19:43:30
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
        int n, ans = 0; string s;
        cin >> n >> s;
        for(int i = 0; auto c: s)
            ans += c - '0' + (++i < n and c ^ '0');
        cout << ans << '\n';
    }();

} // ~W