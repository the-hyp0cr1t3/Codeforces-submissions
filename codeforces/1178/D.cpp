#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
const int N = 1000 + 11;
int nxtprime[N];
vector<bool> prime;

void sieve(int maxn) {
    int i, j, k = 2;
    prime.assign(maxn+1, true);
    nxtprime[2] = 2;
    prime[0] = prime[1] = false;

    for(i = 2; i <= maxn; i+=2)
        prime[i] = i == 2;

    for(i = 3; i*i <= maxn; i+=2) 
        if (prime[i])
            for(j = i*i; j <= maxn; j+=i*2) 
                if (prime[j])
                    prime[j] = false;
    for(i = 3; i <= maxn; i+=2) {
        if (prime[i]) {
            for(j = k+1; j <= i; j++) 
                nxtprime[j] = i;
            k = i;
        }
    }
}

int32_t main() {
    IOS;
    int i, n;
    cin >> n;
    sieve(1010);
    cout << nxtprime[n] << endl;
    for(i = 1; i < n; i++) 
        cout << i << " " << i+1 << endl;
    cout << i << " " << 1 << endl;
    for(i = n; i < nxtprime[n]; i++) 
        cout << i - n + 1 << " " << 2*n - i - 1<< endl;
    return 0;
}