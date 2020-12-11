/**
 🍪 the_hyp0cr1t3
 🍪 11.12.2020 20:20:48
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
int a[N];

int ocoiek() {
    int i, j, n, m, mx = 0;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        cin >> a[i];
    a[n] = INF;
    
    vector<pair<int, double>> q(m);
    for(i = 0; i < m; i++)
        cin >> q[i].first >> q[i].second;

    if(is_sorted(a, a+n)) return cout << 1 << '\n', 0;
    sort(all(q)); reverse(all(q));

    for(i = n-1; ~i; i--)
        if(a[i] > a[i+1]) break;
    i++;
    for(j = 0; j < i; j++)
        chmax(mx, a[j]);

    while(mx > a[i])
        chmax(mx, a[i++]);

    double ans = 1;
    for(j = 0; j < m; j++) {
        if(q[j].first < i) break;
        ans *= 1.0 - q[j].second;
    }
    ans = 1.0 - ans;
    cout << fixed << setprecision(9) << ans << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W 