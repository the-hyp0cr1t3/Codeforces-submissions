/**
 🍪 the_hyp0cr1t3
 🍪 03.12.2021 17:49:04
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

    int64_t i, n;
    cin >> n;

    for(i = 1; i * i <= n; i++);
    int64_t k = i - 1;

    int64_t ans = - k * k;
    for(i = 1; i <= k; i++)
        ans += 2LL * (n / i);

    cout << ans;

} // ~W