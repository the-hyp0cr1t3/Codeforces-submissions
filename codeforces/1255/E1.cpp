#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define DESPACITO 1000000000000000000 //1e18
#define pb push_back
#define sz(x) (int)(x).size()
const int N = 1e5 + 5;
vector<int> primes, v;
vector<bool> prime;
void sieve(int cnt) {
    int i, j;
    prime.assign(cnt+1, true);
    prime[0] = prime[1] = false;

    for(i = 4; i <= cnt; i+=2)
        prime[i] = 0;

    for(i = 3; i*i <= cnt; i+=2) 
        if (prime[i])
            for(j = i*i; j <= cnt; j+=i*2) 
                if (prime[j]) prime[j] = false;

    if (cnt%2 == 0)
        primes.pb(2);
    for(i = 3; i <= cnt; i+=2) 
        if (prime[i] and cnt%i == 0) primes.pb(i);
}
int32_t main() {
    IOS;
    int i, j, n, cnt = 0, a;
    long long ans = DESPACITO;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a;
        cnt += a;
        if (a) v.pb(i);
    }
    if (cnt == 1)
        return cout << -1, 0;
    sieve(cnt);
    for (auto& x: primes) {
        long long res = 0;
        for(i = 0; i < cnt; i+=x)
            for(j = i; j < i + x; j++) 
                res += abs(v[j]-v[i+x/2]);
        ans = min(ans, res);
    } 
    cout << ans;
    return 0;
}