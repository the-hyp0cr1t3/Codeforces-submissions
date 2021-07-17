/**
 🍪 the_hyp0cr1t3
 🍪 17.07.2021 17:33:55
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
    int i, n, k, ans = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    map<int, int> cur;
    for(i = 0; i < k; i++)
        cur[a[i]]++;
    for(; i <= n; i++) {
        ans = max(ans, sz(cur));
        if(!--cur[a[i-k]]) cur.erase(a[i-k]);
        if(i < n) cur[a[i]]++;
    }

    cout << ans;
} // ~W