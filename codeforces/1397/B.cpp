/**
 🍪 the_hyp0cr1t3
 🍪 30.08.2020 20:17:59
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
const int M = 1e6;
int a[N];

template<typename T>
T expo(T A, ll B) {
    T res{1}; while(B) {
        if(B & 1) res = res * A;
        B >>= 1; A = A * A;
    } return res;
}

int32_t main() {
    aylmao
    int i, n, sum = 0, ans = DESPACITO;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];

    sort(a, a+n);

    auto abs = [](int x) {
        return x < 0? -x : x;
    };

    auto Try = [&](int c) {
    	int res = 0;
    	for(i = 0; i < n; i++)
			res += abs(a[i] - expo(c, i));
		return res;    
    };

    for(int c = 1; c <= M; c++) {
        int res = 1;
        for(i = 1; i < n; i++) {
            res *= c;
            if(res > ll(1e16)) break;
        }
        if(i < n) break;
        chmin(ans, Try(c));
    }

    cout << ans;
    return 0;
}	