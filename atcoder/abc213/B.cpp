/**
 🍪 the_hyp0cr1t3
 🍪 08.08.2021 17:30:56
**/
#ifdef W
    #include "k_II.h"
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
    int i, n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    sort(all(a), greater{});
    cout << a[1].second + 1;

} // ~W