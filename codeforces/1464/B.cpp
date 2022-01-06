/**
 🍪 the_hyp0cr1t3
 🍪 07.01.2022 01:19:27
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

    int i, n; int64_t x, y; string s;
    cin >> s >> x >> y;
    n = s.size();
    s = '$' + s;

    if(x > y) {
        swap(x, y);
        for(auto& c: s) if(c ^ '?') c ^= 1;
    }

    vector<int> prefix_zeroes(n + 1), suffix_ones(n + 2);
    for(i = 1; i <= n; i++) {
        prefix_zeroes[i] = prefix_zeroes[i - 1] + (s[i] == '0');
        suffix_ones[n - i + 1] = suffix_ones[n - i + 2] + (s[n - i + 1] != '0');
    }

    int64_t res = 0;
    for(i = 1; i <= n; i++)
        res += s[i] == '0'? y * (i - prefix_zeroes[i]) : x * prefix_zeroes[i];
    int64_t ans = res;

    for(i = 1; i <= n; i++) {
        prefix_zeroes[i] = prefix_zeroes[i - 1] + (s[i] != '1');
        if(s[i] == '?') {
            res -= x * prefix_zeroes[i - 1] + y * (n - i - suffix_ones[i + 1]);
            res += y * (i - prefix_zeroes[i]) + x * suffix_ones[i + 1];
            ans = min(ans, res);
        }
    }

    cout << ans;
} // ~W