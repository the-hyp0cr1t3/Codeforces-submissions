/**
 🍪 the_hyp0cr1t3
 🍪 30.08.2020 20:48:08
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
int a[N];

int32_t main() {
    aylmao
    int i, n;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    if(n == 1) {
    	cout << "1 1" << endl;
    	cout << (-a[0]) << endl;
        cout << "1 1" << endl;
        cout << 0 << endl;
        cout << "1 1" << endl;
        cout << 0 << endl;
    	return 0;
    }
    cout << 1 << " " << n-1 << endl;
    for(i = 0; i < n-1; i++) 
        cout << (n-1)*a[i] << " \n"[i == n-2];
    cout << 2 << " " << n << endl;
    for(i = 1; i < n-1; i++) 
        cout << 0 << " ";
    cout << (n-1)*a[i] << endl;
    cout << 1 << " " << n << endl;
    for(i = 0; i < n; i++) 
        cout << (-n*a[i]) << " \n"[i == n-1];
    return 0;
}