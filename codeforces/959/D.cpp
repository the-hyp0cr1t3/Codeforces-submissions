/**
 🍪 the_hyp0cr1t3
 🍪 19.08.2020 08:52:44
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
const int N = 1e7;
int a[N];
int32_t main() {
    aylmao
    int i, n; 
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];

    set<int> primes;
    vector<int> spf;
    vector<bool> prime;
    [&](int maxn) {
        prime.assign(maxn, true);
        spf.assign(maxn, 0);
        prime[0] = prime[1] = false;
        primes.insert(2);
        spf[2] = 2;
        for(i = 4; i < maxn; i+=2)
            prime[i] = false, spf[i] = 2;
        for(i = 3; i*i < maxn; i+=2) {
            if(prime[i]) {
                for(int j = i*i; j < maxn; j+=i*2) {
                    if(prime[j]) 
                        prime[j] = false, spf[j] = i;
                }
            }
        }
        for(i = 3; i < maxn; i+=2) {
            if(prime[i]) {
                primes.insert(i);
                spf[i] = i;
            }
        }
    }(N);

    auto check = [&](int x) {
        assert(x > 1);
        int p = spf[x];
        while(p > 1) {
            if(!primes.count(p)) return false;
            while(x%p == 0) x /= p;
            p = spf[x];
        }
        return true;
    };

    auto remove = [&](int x) {
        assert(x > 1);
        int p = spf[x];
        while(p > 1) {
            primes.erase(p);
            while(x%p == 0) x /= p;
            p = spf[x];
        }
    };
    
    for(i = 0; i < n; i++) {
        if(check(a[i])) { remove(a[i]); continue; }
        while(!check(++a[i]));
        remove(a[i++]);
        break;
    }

    for(; i < n; i++) {
        assert(sz(primes));
        a[i] = *primes.begin();
        primes.erase(primes.begin());
    }

    for(i = 0; i < n; i++) 
        cout << a[i] << " \n"[i == n-1];
    return 0;
}