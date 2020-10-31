/**
 🍪 the_hyp0cr1t3
 🍪 31.10.2020 21:45:12
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 998244353;
const int N = 50;
int a[N][N], ok[2][N][N];
int64_t fact[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, k, n, K;
    cin >> n >> K;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cin >> a[i][j];

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            ok[0][i][j] = ok[1][i][j] = 1;
            for(k = 0; k < n; k++) {
                ok[0][i][j] &= a[i][k] + a[j][k] <= K;
                ok[1][i][j] &= a[k][i] + a[k][j] <= K;
            }
        }
    }

    auto get_par = [&](int A, vector<int>& par) {
        while(par[A] >= 0) {
            if(par[par[A]] >= 0) par[A] = par[par[A]];
            A = par[A];
        } return A;
    };
    
    auto merge = [&](int A, int B, vector<int>& par) {
        A = get_par(A, par); B = get_par(B, par);
        if(A == B) return false;
        if(-par[A] < -par[B]) swap(A, B);
        par[A] += par[B]; par[B] = A;
        return true;
    };
    
    vector<vector<int>> par(2, vector<int>(n+1, -1));
    for(k = 0; k < 2; k++)
        for(i = 0; i < n; i++)
            for(j = i+1; j < n; j++)
                if(ok[k][i][j]) merge(i, j, par[k]);
    
    fact[0] = 1;
    for(i = 1; i <= n; i++)
        fact[i] = fact[i-1] * i % MOD;

    int64_t ans = 1;
    for(k = 0; k < 2; k++)
        for(i = 0; i < n; i++)
            if(get_par(i, par[k]) == i)
                (ans *= fact[-par[k][i]]) %= MOD;

    cout << ans;
}