/**
 🍪 the_hyp0cr1t3
 🍪 30.08.2020 21:06:57
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

const int N = 100+5;
int a[N];

int the_real_main() {
    int i, j, n, sum = 0, tot = 0, cnt = 0;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i] - 1;
        tot += a[i];
    }
    for(i = 0; i < n; i++) 
        if(a[i] > tot/2) return cout << "T" << endl, 0;
    if(sum&1)
        return cout << (n&1? "HL" : "T") << endl, 0;
    else
        return cout << (n&1? "T" : "HL") << endl, 0;
    return 0;
}

int32_t main() {
    aylmao
    int Q; for(cin >> Q; Q; Q--) the_real_main();
    return 0;
}