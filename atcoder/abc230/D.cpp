/**
 🍪 the_hyp0cr1t3
 🍪 03.12.2021 17:44:38
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

    int i, n, d;
    cin >> n >> d;
    vector<pair<int, int>> a(n);
    for(auto& [x, y]: a) cin >> x >> y;

    sort(a.begin(), a.end(), [](const auto& A, const auto& B) {
        return A.second < B.second;
    });

    int mx = 0, ans = 0;
    for(auto& [x, y]: a) {
        if(x <= mx) continue;
        mx = y + d - 1;
        ans++;
    }

    cout << ans;

} // ~W