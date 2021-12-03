/**
 🍪 the_hyp0cr1t3
 🍪 03.12.2021 17:34:13
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

    int i, n; string s;
    cin >> s; n = s.size();

    string w = "oxx";
    for(auto j: {0, 1, 2}) {
        rotate(w.begin(), w.begin() + 1, w.end());
        bool bad = false;
        for(i = 0; i < n; i++)
            bad |= s[i] != w[i % 3];
        if(!bad) return cout << "Yes", 0;
    }

    cout << "No";

} // ~W