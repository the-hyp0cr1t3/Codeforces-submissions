/**
 🍪 the_hyp0cr1t3
 🍪 04.11.2021 21:22:45
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
        int i; string s, t;
        cin >> s >> t;
        array<int, 26> pos;
        for(i = 0; auto c: s)
            pos[c - 'a'] = i++;

        int ans = 0;
        for(i = 1; i < t.size(); i++)
            ans += abs(pos[t[i] - 'a'] - pos[t[i - 1] - 'a']);

        cout << ans << '\n';
    }();

} // ~W