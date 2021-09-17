/**
 🍪 the_hyp0cr1t3
 🍪 17.09.2021 13:24:46
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n; int64_t ans = 0;
    cin >> n;
    vector<int> a(n + 1), b(n);
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;

    for(i = 0; i < n; i++) {
        ans += min(a[i], b[i]);
        b[i] -= min(a[i], b[i]);
        ans += min(a[i + 1], b[i]);
        a[i + 1] -= min(a[i + 1], b[i]);
    }

    cout << ans << '\n';
} // ~W