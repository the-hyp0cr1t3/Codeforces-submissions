/**
 🍪 the_hyp0cr1t3
 🍪 18.10.2020 19:47:19
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

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n; int64_t ans = -DESPACITO, total = 0;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(i = 0; i < n; i++)
        cin >> a[i].first, a[i].second = i, total += a[i].first;

    sort(all(a), greater{});
    int j = n%3 == 0? 2 : n%3 == 1? 1 : 0;

    int64_t sum = 0;
    for(i = 0; j <= n; j += 3) {
        while(i < j) sum += a[i++].first; 
        if(i < n and (j == n/2 or j == (n+1)/2)) {
            int swp = a[i].first - a[i-1].first;
            sort(a.begin(), a.begin()+i, [](const auto& A, const auto& B) {
                return A.second < B.second;
            });
            bool bad = true;
            for(int z = 1; z < i and bad; z++)
                if(a[z].second == a[z-1].second + 1) bad = false;
            if(bad) {
                sum += swp;
                chmax(ans, sum - (total - sum));
                sum -= swp;
                continue;
            }
        }
        chmax(ans, sum - (total - sum));
    } cout << ans << '\n';
}