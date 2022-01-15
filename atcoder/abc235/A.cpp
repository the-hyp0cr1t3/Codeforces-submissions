/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 17:30:52
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

    int i, j, n; string s;
    cin >> s;

    int ans = 0;
    for(i = 0; i < 3; i++) {
        int sum = 0;
        for(j = 0; j < 3; j++)
            sum = sum * 10 + s[(i + j) % 3] - '0';
        ans += sum;
    }

    cout << ans;

} // ~W