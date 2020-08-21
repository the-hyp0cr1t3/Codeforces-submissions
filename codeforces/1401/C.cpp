/**
 🍪 the_hyp0cr1t3
 🍪 21.08.2020 20:34:04
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
int a[N], b[N];

int the_real_main() {
    int i, n;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    for(i = 0; i < n; i++) 
        b[i] = a[i];
    int mn = *min_element(a, a+n);
    sort(b, b+n);
    for(i = 0; i < n; i++)
        if(a[i]%mn and a[i] ^b[i]) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    return 0;
}

int32_t main() {
    aylmao
    int Q; for(cin >> Q; Q; Q--) the_real_main();
    return 0;
}