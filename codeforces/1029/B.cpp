/**
 🍪 the_hyp0cr1t3
 🍪 24.08.2020 23:38:48
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
// #define int long long
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
int a[N];

int32_t main() {
    aylmao
    int i, n, ans = 0, cur = 1, prv = 0;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    prv = a[0];
    for(i = 1; i < n; i++) {
        if(a[i] <= prv*2) cur++;
        else chmax(ans, cur), cur = 1;
        prv = a[i];
    }
    chmax(ans, cur);
    cout << ans;
    return 0;
}