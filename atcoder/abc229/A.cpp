/**
 🍪 the_hyp0cr1t3
 🍪 27.11.2021 17:30:57
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

    string s, t;
    cin >> s >> t;

    cout << (s[0] == '.' and s[1] == '#' and t[0] == '#' and t[1] == '.'
        or t[0] == '.' and t[1] == '#' and s[0] == '#' and s[1] == '.'? "No" : "Yes");


} // ~W