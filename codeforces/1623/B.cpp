/**
 🍪 the_hyp0cr1t3
 🍪 28.12.2021 19:21:17
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
        int i, j, n;
        cin >> n;
        vector<array<int, 3>> a(n);
        vector<int> dead(n + 1);
        for(auto& [l, r, x]: a)
            cin >> l >> r, x = r - l + 1;

        for(int z = 0; z < n; z++) {
            int best = n + 1, besti = -1;
            for(i = 0; auto& [l, r, x]: a) {
                if(x < best) best = x, besti = i;
                i++;
            }

            for(best = 0, i = a[besti][0]; i <= a[besti][1]; i++)
                if(!dead[i]) j = i, best++;
            assert(best == 1);

            dead[j] = true;
            a[besti][2] = n + 1;
            for(auto& [l, r, x]: a)
                x -= x <= n and l <= j and j <= r;

            cout << a[besti][0] << ' ' << a[besti][1] << ' ' << j << '\n';
        }

    }();

} // ~W