/**
 🍪 the_hyp0cr1t3
 🍪 27.11.2021 17:38:33
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

    int i, j, n, k; string s;
    cin >> s >> k;

    n = s.size();
    int cur = 0, ans = 0;
    for(i = j = 0; i < n; i++) {
        while(j < n and (s[j] == 'X' or cur < k))
            cur += s[j++] == '.';
        ans = max(ans, j - i);
        cur -= s[i] == '.';
    }

    cout << ans;
} // ~W