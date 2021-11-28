/**
 🍪 the_hyp0cr1t3
 🍪 28.11.2021 20:18:16
**/
#ifdef W
    #include <k_II.h>
    #undef e
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int N = 1e6 + 5;

    array<int, N> spf; iota(spf.begin(), spf.end(), 0);
    for(int z = 4; z < N; z += 2) spf[z] = 2;
    for(int z = 3; z*z < N; z += 2) if(spf[z] == z) {
        for(int y = z*z; y < N; y += z*2)
            if(spf[y] == y) spf[y] = z;
    }

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, n, e;
        cin >> n >> e;
        vector<int> a(n);
        vector<int> nxtp(n + e, n), nxtc(n + e, n);
        vector<int> curp(e), curc(e);
        for(i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] = x == 1? 0 : spf[x] == x? 1 : -1;
            curp[i % e] = i;
            curc[i % e] = i;
        }

        for(i = 0; i < e; i++) {
            nxtp[n + i] = n + i;
            nxtc[n + i] = n + i;
        }

        for(auto& x: curp)
            x += e;
        for(auto& x: curc)
            x += e;

        // ps(a);
        for(i = n - 1; ~i; i--) {
            if(a[i] == 1)
                curp[i % e] = i;
            if(a[i] == -1)
                curc[i % e] = i;
            nxtp[i] = curp[i % e];
            nxtc[i] = curc[i % e];
        }

        int64_t ans = 0;
        for(i = 0; i < n; i++) {
            int j = nxtp[i];
            if(nxtc[i] < j or j >= n) continue;
            int k = min(nxtp[j + e], nxtc[i]);
            // tr(i, j, k);
            ans += (k - j) / e - (j == i);
        }

        cout << ans << '\n';
        // tr(ans);
        // ps();
        // ps();
    }();

} // ~W