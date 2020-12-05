/**
 🍪 the_hyp0cr1t3
 🍪 05.12.2020 20:25:58
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
    int i, n;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];

    int64_t res = 0, ans;
    for(i = 1; i < n; i++)
        res += abs(a[i] - a[i-1]);
    ans = res;

    chmin(ans, res - abs(a[0]-a[1]));
    chmin(ans, res - abs(a[n-1]-a[n-2]));
    for(i = 1; i+1 < n; i++)
        chmin(ans, res - abs(a[i]-a[i-1]) - abs(a[i]-a[i+1]) + abs(a[i-1]-a[i+1]));
    cout << ans << '\n';

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W 