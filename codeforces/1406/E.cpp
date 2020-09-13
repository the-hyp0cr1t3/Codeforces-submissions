/**
 🍪 thew6rst
 🍪 13.09.2020 16:03:34
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
// #define endl '\n'
#define pb emplace_back
// #define int int64_t
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 1e5 + 1;
const int SQRT = 316;

int32_t main() {
    aylmao
    int i, j, n, ans = 1;
    cin >> n;

    vector<bool> isPrime(n+1, true);
    vector<int> bigprimes, smallprimes;
    bigprimes.reserve(9600);
    smallprimes.reserve(SQRT);

    for(i = 2; i <= n; i++) {
        if(!isPrime[i]) continue;
        for(j = 2*i; j <= n; j+=i)
            isPrime[j] = false;
        if(i < SQRT) smallprimes.pb(i);
        else bigprimes.pb(i);
    }

    auto askA = [&n](ll k) {
        if(k > n) return 0ll;
        cout << "A " << k << endl;
        cin >> k; return k;
    };

    auto askB = [](int k) {
        cout << "B " << k << endl;
        cin >> k; return k;
    };

    for(auto p: smallprimes) {
        askB(p); int x = p;
        while(askA(x)) x *= p;
        ans *= x / p;
    }

    if(ans > 1) {
        for(auto p: bigprimes)
            if(askA(1ll*ans*p)) ans *= p;
    } else {
        i = 0;
        while(i < sz(bigprimes)) {
            int mid = i + sz(bigprimes)-1 >> 1;
            for(j = i; j <= mid; j++) askB(bigprimes[j]);
            if(askA(1) > sz(bigprimes)-mid) {
                for(j = i; j <= mid; j++)
                    if(askA(bigprimes[j]))
                        ans *= bigprimes[j];
                break;
            } else i = mid + 1;
        }        
    }

    cout << "C " << ans << endl;
}