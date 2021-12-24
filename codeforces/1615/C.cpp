/**
 🍪 the_hyp0cr1t3
 🍪 24.12.2021 20:13:57
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
        int i, n; string a, b;
        cin >> n >> a >> b;
        int cnt[2][2] = {};
        for(i = 0; i < n; i++)
            cnt[a[i] == b[i]][a[i] == '1']++;

        if(R::count(a, '1') == n) {
            cout << (a == b? 0 : R::count(b, '1') == 1? 1 : -1) << '\n';
            return;
        }

        if(R::count(a, '0') == n) {
            cout << (a == b? 0 : -1) << '\n';
            return;
        }

        int ans = n + 1;
        if((cnt[1][0] + cnt[1][1] & 1) and cnt[1][1] - cnt[1][0] == 1)
            ans = min(ans, cnt[1][0] + cnt[1][1]);
        if((~(cnt[0][0] + cnt[0][1]) & 1) and cnt[0][1] == cnt[0][0])
            ans = min(ans, cnt[0][0] + cnt[0][1]);
        if(cnt[1][0] + cnt[1][1] == n) ans = 0;

        cout << (ans > n? -1 : ans) << '\n';

    }();

} // ~W