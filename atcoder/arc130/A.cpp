/**
 🍪 the_hyp0cr1t3
 🍪 28.11.2021 17:31:10
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

    int i, j, n; string s;
    cin >> n >> s;
    int64_t ans = 0;
    for(i = j = 0; i < n; i = j) {
        while(j < n and s[i] == s[j]) j++;
        ans += 1LL * (j - i) * (j - i - 1) / 2;
    }

    cout << ans << '\n';
} // ~W