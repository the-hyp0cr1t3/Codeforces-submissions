#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
#define MOD 1073741824

vector<int> d;
vector<bool> prime;

void modmul (int *a, int b) {
    *a = (*a * b) % MOD;
}

void sieve(int maxn) {
    int i, j, k;
    prime.assign(maxn+1, true);
    d.assign(maxn+1, 1);
    for(i = 2; i <= maxn; i+=2) {
        prime[i] = i == 2;
        k = i;
        int cnt = 0;
        while(k%2==0)
            cnt++, k/=2;
        modmul(&d[i], cnt+1);
    }

    for(i = 3; i <= maxn; i+=2) {
        if (prime[i]) {
            for(j = i; j <= maxn; j+=i) {
                k = j;
                int cnt = 0;
                while(k%i==0)
                    cnt++, k/=i;
                modmul(&d[j], cnt+1);
                if (prime[j])
                    prime[j] = false;
            }
        }
    }
}

int32_t main() {
    IOS;
    int i, j, k, a, b, c;
    ll ans = 0;
    cin >> a >> b >> c;
    sieve(a*b*c);
    for(i = 1; i <= a; i++)
        for(j = 1; j <= b; j++)
            for(k = 1; k <= c; k++) 
                ans = (ans + d[i*j*k]) % MOD;
    cout << ans;
    return 0;
}