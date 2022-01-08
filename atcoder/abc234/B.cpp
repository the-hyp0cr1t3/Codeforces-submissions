/**
 🍪 the_hyp0cr1t3
 🍪 08.01.2022 17:32:04
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

    int i, j, n;
    cin >> n;

    int64_t ans = 0;
    vector<int64_t> x(n), y(n);
    for(i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        for(j = 0; j < i; j++)
            ans = max(ans, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    }

    cout << fixed << setprecision(9) << sqrtl(ans);

} // ~W