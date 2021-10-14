/**
 🍪 the_hyp0cr1t3
 🍪 14.10.2021 19:17:35
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
        int i, n;
        cin >> n;
        for(i = 1; n; i++) {
            if(i % 3 == 0 or i % 10 == 3)
                continue;
            if(!--n) break;
        }

        // while(i % 3 == 0 and i % 10 == 3) i++;

        cout << i << '\n';

    }();

} // ~W