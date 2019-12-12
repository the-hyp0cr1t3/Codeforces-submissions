#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define s second
#define f first
#define ins insert
#define pb push_back
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int k;
vector<bool> prime;
map <int,vector<pii>> factors;
map <vector<pii>, int> mp; 

void sieve(int maxn) {
    int i, j, cnt;
    prime.assign(maxn+1, true);
    prime[0] = prime[1] = false;

    for(i = 2; i <= maxn; i+=2) {
        prime[i] = i == 2;
        j = i, cnt = 0;
        while(j%2==0) j/=2, cnt++;
        if (cnt%k)
            factors[i].pb({2, cnt%k});
    }

    for(i = 3; i <= maxn; i+=2) {
        if (prime[i]) {
            for(j = i; j <= maxn; j+=i) {
                if (prime[j]) prime[j] = false;
                int K = j; cnt = 0;
                while(K%i==0) K/=i, cnt++;
                if (cnt%k)
                    factors[j].pb({i, cnt%k});
            }
        }
    }
}

int32_t main() {
    IOS;
    int i, n, a;
    cin >> n >> k;
    sieve(N);
    for(i = 0; i < n; i++) {
        cin >> a;
        mp[factors[a]]++;
    }
    ll ans = 0;
    for (auto& x: mp) {
        vector<pii> q;
        for (auto& y: x.f) 
            q.pb({y.f,k-y.s});
        if (x.f == q)
            ans += 1ll*x.s*(x.s-1);
        else if (mp.count(q)) 
            ans += 1ll*mp[q]*x.s;
    }
    ans /= 2;
    cout << ans;
    return 0;
}