/**
 🍪 the_hyp0cr1t3
 🍪 18.08.2020 19:33:52
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
// #define int long long
#define endl '\n'
#define pb emplace_back
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
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
    int i, n;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    for(int j = 29; ~j; j--) {
        int cnt = 0;
        for(i = 0; i < n; i++) 
            if(a[i]>>j&1) swap(a[i], a[0]), cnt++;
        if(cnt == 1) {
            for(i = 0; i < n; i++) 
                cout << a[i] << " \n"[i == n-1];
            return 0;
        }
    }
    for(i = 0; i < n; i++) 
        cout << a[i] << " \n"[i == n-1];
    return 0;
}