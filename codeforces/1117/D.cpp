#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define MOD 1000000007  //1e9 + 7
#define ll long long
int m;
typedef vector<vector<int> > matrix;

matrix mul(matrix A, matrix B) {
    matrix C(m+1, vector<int>(m+1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                ll a = A[i][k], b = B[k][j];
                ll c = (a * b) % MOD;
                C[i][j] = (C[i][j] + (int)c) % MOD;
            }
        }
    }
    return C;
}

matrix pow(matrix A, ll p) {
    if (p == 1)
        return A;
    if (p & 1)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int32_t main() {
    IOS;
    int i, j;
    ll n, ans = 0;
    cin >> n >> m;
    if (n < m)
        return cout << 1, 0;
    if (n == m)
        return cout << 2, 0;
    matrix T(m+1, vector<int>(m+1));
    T[1][1] = T[1][m] = 1;
    for (i = 2; i <= m; i++)
        T[i][i-1] = 1;
    vector<int> F(m+1, 1);
    F[1] = 2;
    T = pow(T, n-m);
    for(i = 1; i <= m; i++) 
        ans = (ans + T[1][i]*F[i]) % MOD;
    cout << ans;
    return 0;
}