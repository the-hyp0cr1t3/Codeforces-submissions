#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define ff first
#define ss second
#define rev(a) reverse(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins insert
#define pb push_back
#define sz(x) (int)(x).size()
#define MOD 998244353
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int, int> pii;
const int N = 1e6 + 5;
int cnt[N];
ll p[N];

template <typename T, typename T1>
T expo (T a, T1 b) {
    if (b == 0)
        return 1;
    if (b & 1)
        return (int)(1ll * a * expo(a, b-1) % MOD);
    a = expo(a, b/2);
    return (int)(1ll * a * a % MOD);
}

int modinv (int a) {
    return expo(a, MOD-2);
}

int32_t main() {
    IOS;
    int i, j, n, k, a;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> k;
        for(j = 0; j < k; j++) {
            cin >> a;
            cnt[a]++;
            p[a] += modinv(k);
            p[a] %= MOD;
        }
    }
    ll res = 0;
    for(i = 0; i < N; i++) {
        res += (p[i]*(n-cnt[i])) % MOD;
        res %= MOD;
    }
    res *= modinv(expo(n, 2));
    res %= MOD;
    res = 1 - res;
    res %= MOD;
    if (res < 0) res += MOD;
    cout << res;
    return 0;
}