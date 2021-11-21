/**
 🍪 the_hyp0cr1t3
 🍪 21.11.2021 17:40:27
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

    int i, n, L = -1, R = 1e9 + 1;
    cin >> n;
    for(i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        L = max(L, l);
        R = min(R, r);
        cout << max(0, L - R + 1) / 2 << '\n';
    }

} // ~W