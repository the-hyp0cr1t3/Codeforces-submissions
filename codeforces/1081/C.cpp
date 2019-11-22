#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
#define MOD 998244353
typedef pair<int, int> pii;
const int N = 2000 + 5;
int fact[N], factinv[N], inv[N];

int nCr (int n, int r) {
    if (r > n)
        return 0;
    int ans = (int)((1ll * factinv[r] * factinv[n-r]) % MOD);
    ans = (int)((1ll * ans * fact[n]) % MOD);
    return ans;
}

template<typename T>
T mod(T x) {
    x %= MOD;
    if (x < 0)
        x += MOD;
    return x;
}

template<typename T>
T modinv (T x) {
    x = mod(x);
    if (x == 1)
        return 1;
    return ((int)mod(1ll * (-MOD/x) * (inv[MOD%x] % MOD)));
}

template<typename T>
void preprocess (T n) {
    fact[0] = factinv[0] = 1;
    for(T i = 1; i <= n; i++) {
        fact[i] = (int) ((1ll * fact[i-1] * i) % MOD);
        inv[i] = modinv(i);
        factinv[i] = (int) ((1LL * factinv[i - 1] * inv[i]) % MOD);
    }
}

template <typename T, typename T1>
T expo (T a, T1 b) {
    if (b == 0)
        return 1;
    if (b & 1)
        return (int)(1ll * a * expo(a, b-1) % MOD);
    a = expo(a, b/2);
    return (int)(1ll * a * a % MOD);
}

int32_t main() {
    IOS;
    int i, n, m, k;
    cin >> n >> m >> k;
    preprocess(n);
    ll ans = (1ll*m*expo(m-1, k))%MOD;
    ans = (ans * nCr(n-1, k))%MOD;
    cout << ans;
    return 0;
}