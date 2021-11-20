/**
 🍪 the_hyp0cr1t3
 🍪 20.11.2021 17:36:12
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

    int i, n, k, ans = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& x: a) cin >> x;

    for(i = k; a[i - 1] >= 0; i = -a[i - 1]) {
        ans++;
        a[i - 1] *= -1;
    }

    cout << ans << '\n';
} // ~W