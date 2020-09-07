/**
 🍪 thew6rst
 🍪 07.09.2020 09:18:15
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
#define int int64_t
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 2e5 + 5;
int a[N];

int the_real_main() {
    int i, n;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    int sum = 0, remneg = 0;
    for(i = n-2; ~i; i--) {
        if(a[i] > 0)
            remneg -= min(remneg, a[i]);
        else
            remneg += -a[i];
    }
    cout << remneg << endl;
    return 0;
}

int32_t main() {
    aylmao
    int Q; for(cin >> Q; Q; Q--) the_real_main();
    return 0;
}