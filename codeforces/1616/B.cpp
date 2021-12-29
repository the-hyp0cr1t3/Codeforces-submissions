/**
 🍪 the_hyp0cr1t3
 🍪 29.12.2021 21:09:45
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
        int i, n; string s;
        cin >> n >> s;
        for(i = 1; i < n; i++)
            if(s[i] > s[i - 1]) break;

        string ans;
        ans += s[0]; ans += s[0];
        string t = s.substr(0, i);
        s = t;
        reverse(t.begin(), t.end());
        s += t;

        ans = min(ans, s);
        cout << ans << '\n';
    }();

} // ~W