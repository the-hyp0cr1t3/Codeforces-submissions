/**
 🍪 the_hyp0cr1t3
 🍪 18.10.2021 22:04:17
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int N = 2e5;

    array<int, N> spf; iota(spf.begin(), spf.end(), 0);
    for(int z = 4; z < N; z += 2) spf[z] = 2;
    for(int z = 3; z*z < N; z += 2) if(spf[z] == z) {
        for(int y = z*z; y < N; y += z*2)
            if(spf[y] == y) spf[y] = z;
    }

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, n;
        cin >> n;
        vector<int> a(n), ans(n);
        iota(ans.begin(), ans.end(), 1);
        for(auto& x: a) cin >> x;
        int s = accumulate(a.begin(), a.end(), 0);

        if(spf[s] == s and s > 1) {
            for(i = 0; i < n; i++) {
                if(!(spf[s - a[i]] == s - a[i] and s - a[i] > 1)) {
                    ans.erase(ans.begin() + i);
                    break;
                }
            }
        }

        cout << ans.size() << '\n';
        for(auto& x: ans) cout << x << ' ';
        cout << '\n';

    }();

} // ~W