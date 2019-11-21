#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define min(a,b) (a<b?a:b)
#define pb push_back
const int N = 1e6 + 5;
const int M = 2e7 + 5;
int cnt[M], pref[M];
vector<bool> prime;

void sieve(int maxn) {
    int i, j;
    prime.assign(maxn+1, true);
    prime[0] = prime[1] = false;

    for(i = 2; i <= maxn; i++) 
        if (prime[i]) {
            for(j = i; j <= maxn; j+=i) {
                pref[i] += cnt[j];
                if (prime[j])
                    prime[j] = false;
            }
        }
}

int32_t main() {
    IOS;
    int i, n, mx = 0, a, q;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a, mx = max(mx, a), cnt[a]++;
    sieve(mx);
    for(i = 1; i <= mx; i++) 
        pref[i] += pref[i-1];
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l > mx)
            cout << 0 << endl;
        else
            r = min(r, mx), cout << pref[r] - pref[l-1] << endl;
    }
    return 0;
}