#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define MOD 1000000007  //1e9 + 7
#define pb push_back
const int N = 1e6 + 5;
const int MAXFACTORS = 1344 + 1; //1344 for 10^9, 103680 for 10^18

int dp[N];
vector<int> spf, primes;
vector<bool> prime;

void sieve(int maxn) {
    int i, j;
    spf.assign(maxn+1, 0);
    prime.assign(maxn+1, true);
    primes.pb(2);
    prime[0] = prime[1] = false;

    for(i = 2; i <= maxn; i+=2)
        prime[i] = i == 2, spf[i] = 2;

    for(i = 3; i*i <= maxn; i+=2) 
        if (prime[i])
            for(j = i*i; j <= maxn; j+=i*2) 
                if (prime[j])
                    prime[j] = false, spf[j] = i;
    for(i = 3; i <= maxn; i+=2) 
        if (prime[i]) spf[i] = i, primes.pb(i);
}

template<typename T>
int getfactors(int x, T &&factors, bool sorted = false) {
    static int buffer[5000];
    int fcount = 0;
    factors[fcount++] = 1;
 
    while (x != 1) {
        int p = spf[x], exp = 0;
        while (x % p == 0)
            x /= p, exp++;
 
        int prvcount = fcount;
 
        for (int e = 1; e <= exp; e++)
            for (int i = 0; i < prvcount; i++) {
                factors[fcount] = factors[fcount - prvcount] * p;
                fcount++;
            }
 
        if (sorted && prvcount > 1) {
            for (int section = prvcount; section < fcount; section *= 2)
                for (int i = 0; i + section < fcount; i += 2 * section) {
                    merge(factors + i, factors + i + section, factors + i + section, factors + i + 2 * section, buffer);
                    copy(buffer, buffer + 2 * section, factors + i);
                }
        }
    }
    return fcount;
}
int factors[MAXFACTORS];

int32_t main() {
    IOS;
    sieve(N);
    int i, j, n, a, ans = 0;
    cin >> n;
    dp[0] = 1;
    for(i = 0; i < n; i++) {
        cin >> a;
        int cnt = getfactors(a, factors, 1);
        for(j = cnt-1; j >= 0; j--) 
            if (factors[j] <= n)
                dp[factors[j]] = (dp[factors[j]] + dp[factors[j]-1]) % MOD;
    }
    for(i = 1; i <= n; i++) 
        ans = (ans + dp[i]) % MOD;
    cout << ans;
    return 0;
}