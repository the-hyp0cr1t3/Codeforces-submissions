#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define long int64_t
using namespace std;
#define MOD 1000000007  //1e9 + 7
#define min(a,b) (a<b?a:b)
const int N = 2e5 + 5;
int fact[N], factinv[N], inv[N];

template<typename T, typename T1>
T nCr (T n, T1 r) {
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
    int i, n, k, t;
    long T, S = 0, ans = 0, mi = 1, prvmi = 0, j, sigma = 1;
    cin >> n >> T;
    fact[0] = factinv[0] = 1;
    for(i = 1; i < N; i++) {
        fact[i] = (int) ((1ll * fact[i-1] * i) % MOD);
        inv[i] = modinv(i);
        factinv[i] = (int) ((1LL * factinv[i - 1] * inv[i]) % MOD);
    }
    for(i = 1; i <= n; i++, mi++) {
        cin >> t;
        S += t;
        if (S > T)
            break;
        mi = min(mi, T-S);
        if (mi > prvmi)
            for(j = mi; j > prvmi; j--)
                sigma = mod(sigma + nCr(i, j));
        else
            for(j = prvmi; j > mi; j--)
                sigma = mod(sigma - nCr(i, j));
        int modinv = expo(2, i);
        modinv = modinv < N? inv[modinv]: expo(modinv, MOD-2);
        long Pi = mod(sigma * modinv);
        ans = mod(ans + Pi);
        sigma = mod(sigma * 2);
        sigma = mod(sigma + nCr(i, mi+1));
        sigma = mod(sigma - nCr(i+1, mi+1));
        prvmi = mi;
    }
    cout << ans;
    return 0;
}