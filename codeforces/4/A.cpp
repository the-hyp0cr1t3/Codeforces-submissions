/**
 🍪 the_hyp0cr1t3
 🍪 17.08.2020 02:02:59
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
// #define int long long
#define endl '\n'
#define sz(x) int((x).size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5+5;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n;
    cin >> n;
    cout << (n&1 or n == 2? "NO" : "YES");
    return 0;
}