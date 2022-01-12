/**
 🍪 the_hyp0cr1t3
 🍪 12.01.2022 17:36:58
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
    while(tests--) [&]() {
        int i, n, l, y = 0;
        cin >> n >> l;
        vector<int> cnt(l);
        while(n--) {
            int x; cin >> x;
            for(i = 0; i < l; i++)
                cnt[i] += x >> i & 1? 1 : -1;
        }

        for(i = 0; i < l; i++)
            if(cnt[i] > 0) y |= 1 << i;

        cout << y << '\n';

    }();

} // ~W