/**
 🍪 the_hyp0cr1t3
 🍪 21.08.2021 17:34:22
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
const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, j, n, m;
    cin >> n >> m;
    vector<int> a(N), ans{ 1 };
    while(n--) {
        int x; cin >> x;
        a[x]++;
    }

    for(i = 2; i < N; i++)
        for(j = 2*i; j < N; j += i)
            a[i] += a[j];

    for(i = 2; i <= m; i++) {
        bool bad = a[i];
        for(j = 2; j * j <= i; j++) {
            if(i % j == 0)
                bad |= a[j] | a[i / j];
        }
        if(!bad) ans.pb(i);
    }

    cout << sz(ans) << '\n';
    for(auto& x: ans) cout << x << '\n';

} // ~W