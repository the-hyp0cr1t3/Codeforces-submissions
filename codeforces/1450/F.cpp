/**
 🍪 the_hyp0cr1t3
 🍪 07.12.2020 16:27:31
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int ocoiek() {
    int i, j, n, ans = 0;
    cin >> n;
    vector<int> a(n), cnt(n+1), end(n+1);
    for(i = 0; i < n; i++) {
        cin >> a[i]; cnt[a[i]]++;
        if(i and a[i] == a[i-1]) {
            end[a[i]]++;
            end[a[i-1]]++;
            ans++;
        }
    } end[a[0]]++; end[a[n-1]]++;

    if(*max_element(all(cnt)) > (n+1)/2)
        return cout << -1 << '\n', 0;
    
    ans += max(0, *max_element(all(end)) - ans - 2);
    cout << ans << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W 