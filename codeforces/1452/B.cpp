/**
 🍪 the_hyp0cr1t3
 🍪 20.11.2020 13:27:32
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
    int i, n; int64_t sum = 0;
    cin >> n;
    multiset<int> s;
    for(i = 0; i < n; i++)
        cin >> a[i], s.insert(a[i]), sum += a[i];

    int64_t ans = 0;
    for(i = 0; i < n; i++) {
        s.erase(s.find(a[i]));
        int64_t need = 1ll * *s.rbegin() * (n-1) - sum;
        if(need >= 0)
            chmax(ans, need);
        else
            chmax(ans, ((n-1) - abs(need) % (n-1)) % (n-1));
        s.insert(a[i]);
    } cout << ans << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W