/**
 🍪 the_hyp0cr1t3
 🍪 26.11.2021 17:14:16
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
    auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
    auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

    const int N = 5e6 + 5;
    array<int, N> cnt{}, mult{};
    array<int64_t, N> ans{};

    int i, j, n, g = 0;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) {
        cin >> x;
        cnt[x]++;
        g = __gcd(g, x);
    }

    for(i = N - 1; i; i--) {
        for(j = i; j < N; j += i)
            mult[i] += cnt[j];
        ans[i] = 1LL * cnt[i] * i;
        for(j = 2 * i; j < N; j += i)
            chmax(ans[i], ans[j] + 1LL * (mult[i] - mult[j]) * i);
    }

    cout << ans[g];

} // ~W