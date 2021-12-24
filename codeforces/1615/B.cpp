/**
 🍪 the_hyp0cr1t3
 🍪 24.12.2021 20:07:11
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
    const int LG = 24, N = 2e5 + 5;
    array<array<int, N>, LG> cnt{};
    for(int j = 0; j < LG; j++)
        for(int i = 1; i < N; i++)
            cnt[j][i] = cnt[j][i - 1] + (i >> j & 1);

    int tests; cin >> tests;
    while(tests--) [&]() {
        int l, r;
        cin >> l >> r;
        int ans = r - l;
        for(int i = 0; i < LG; i++)
            ans = min(ans, r - l + 1 - (cnt[i][r] - cnt[i][l - 1]));
        cout << ans << '\n';
    }();

} // ~W