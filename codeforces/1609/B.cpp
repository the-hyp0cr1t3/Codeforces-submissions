/**
 🍪 the_hyp0cr1t3
 🍪 28.11.2021 20:09:43
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

    int i, n, q; string s;
    cin >> n >> q >> s;
    int ans = 0;
    auto check = [&](int pos) {
        return 0 <= pos and pos + 2 < n and s[pos] == 'a' and s[pos + 1] == 'b' and s[pos + 2] == 'c';
    };

    for(i = 0; i + 2 < n; i++)
        ans += check(i);

    while(q--) {
        int pos; char c;
        cin >> pos >> c;
        --pos;
        ans -= check(pos - 2) or check(pos - 1) or check(pos);
        s[pos] = c;
        ans += check(pos - 2) or check(pos - 1) or check(pos);

        cout << ans << '\n';
    }

} // ~W