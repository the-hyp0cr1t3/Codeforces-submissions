/**
 🍪 the_hyp0cr1t3
 🍪 20.11.2021 17:31:27
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

    int s, t, x;
    cin >> s >> t >> x;
    if(s < t)
        cout << (s <= x and x <= t? "Yes" : "No");
    else
        cout << (x < t or x >= s? "Yes" : "No");

} // ~W