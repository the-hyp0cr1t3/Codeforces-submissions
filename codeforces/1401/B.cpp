/**
 🍪 the_hyp0cr1t3
 🍪 21.08.2020 20:24:09
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
    int i, ans = 0; array<int, 3> a, b;
    for(i = 0; i < 3; i++) 
        cin >> a[i];
    for(i = 0; i < 3; i++) 
        cin >> b[i];
    ans = min(a[2], b[1]);
    a[2] -= ans;
    b[1] -= ans;
    int take = min(a[2], b[2]);
    a[2] -= take;
    b[2] -= take;
    take = min(a[0], b[2]);
    a[0] -= take;
    b[2] -= take;
    take = min(a[1], b[1]);
    a[1] -= take;
    b[1] -= take;
    take = min(a[1], b[0]);
    a[1] -= take;
    b[0] -= take;
    ans -= min(a[1], b[2]);
    ans *= 2;
    cout << ans << endl;
    return 0;
}

int32_t main() {
    aylmao
    int Q; for(cin >> Q; Q; Q--) the_real_main();
    return 0;
}