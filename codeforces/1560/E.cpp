/**
 🍪 the_hyp0cr1t3
 🍪 19.10.2021 18:30:02
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int M = 26;

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, k, p, q, n; string s, order;
        cin >> s;
        array<int, M> cnt{};
        for(auto c: views::reverse(s))
            if(!cnt[c - 'a']++) order += c;
        ranges::reverse(order);

        for(i = 0; i < order.size(); i++) {
            j = order[i] - 'a';
            if(cnt[j] % (i + 1))
                return cout << -1 << '\n', 0;
            cnt[j] /= i + 1;
        }

        int len = accumulate(cnt.begin(), cnt.end(), 0);
        string ans = s.substr(0, len);

        for(i = j = 0, k = len; i < order.size(); i++) {
            for(p = j, q = k; q - k < len - cnt[order[i] - 'a']; p++, q++) {
                while(p - j < len and s[p] == order[i]) p++;
                if(p == j + len or s[p] ^ s[q])
                    return cout << -1 << '\n', 0;
            }
            while(p - j < len and s[p] == order[i]) p++;
            if(p < j + len)
                return cout << -1 << '\n', 0;

            len -= cnt[order[i] - 'a'];
            cnt[order[i] - 'a'] = 0;
            j = k; k += len;
        }

        cout << ans << ' ' << order << '\n';
        return 0;
    }();

} // ~W