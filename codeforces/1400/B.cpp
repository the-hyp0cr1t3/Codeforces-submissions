/**
 🍪 the_hyp0cr1t3
 🍪 25.08.2020 20:10:36
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define endl '\n'
#define pb emplace_back
#define int long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 2e5+5;

int the_real_main() {
    int i, a[2], cnt[2], w[2], ans = 0;
    for(i = 0; i < 2; i++) 
        cin >> a[i];
    for(i = 0; i < 2; i++) 
        cin >> cnt[i];
    for(i = 0; i < 2; i++) 
        cin >> w[i];
    if(w[0] > w[1]) swap(w[0], w[1]), swap(cnt[0], cnt[1]);
    
    for(i = 0; i <= cnt[0] and i*w[0] <= a[0]; i++) {
        int _0take0 = i;
        int _1take0 = min(cnt[1], (a[0] - i*w[0]) / w[1]);
        int _0take1 = min(cnt[0]-i, a[1]/w[0]);
        int _1take1 = min(cnt[1] - _1take0, (a[1] - w[0]*_0take1) / w[1]);
        chmax(ans, _0take0 + _1take0 + _0take1 + _1take1);
    }
    cout << ans << endl;
    return 0;
}

int32_t main() {
    aylmao
    int Q; for(cin >> Q; Q; Q--) the_real_main();
    return 0;
}   