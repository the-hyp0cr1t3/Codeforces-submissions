/**
 🍪 the_hyp0cr1t3
 🍪 25.10.2021 14:30:21
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int LG = 30;

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, n;
        cin >> n;
        array<int, LG> cnt{};
        for(i = 0; i < n; i++) {
            int a; cin >> a;
            for(j = 0; j < LG; j++)
                cnt[j] += a >> j & 1;
        }

        int g = 0;
        for(i = 0; i < LG; i++)
            g = gcd(g, cnt[i]);

        for(i = 1; i <= n; i++)
            if(!(g % i)) cout << i << ' ';
        cout << '\n';
    }();

} // ~W