/**
 🍪 the_hyp0cr1t3
 🍪 03.01.2022 20:43:33
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
        int i, n;
        cin >> n;
        vector<int> ans(n + 1);

        auto query = [](int x) {
            cout << "? " << x << endl;
            cin >> x; return x;
        };

        for(i = 1; i <= n; i++) {
            if(ans[i]) continue;
            while(query(i) ^ i);
            int prv = i;
            while(true) {
                int x = query(i);
                ans[prv] = x;
                prv = x;
                if(prv == i) break;
            }
        }

        cout << '!';
        for(i = 1; i <= n; i++)
            cout << ' ' << ans[i];
        cout << endl;
    }();

} // ~W