/**
 🍪 the_hyp0cr1t3
 🍪 27.11.2021 17:35:45
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

    int i, n; int64_t ans = 0, w;
    cin >> n >> w;
    vector<array<int64_t, 2>> a(n);
    for(auto& [x, y]: a)
        cin >> x >> y;

    sort(a.rbegin(), a.rend());
    for(auto& [x, y]: a) {
        int64_t take = min(w, y);
        w -= take;
        ans += take * x;
    }

    cout << ans;

} // ~W