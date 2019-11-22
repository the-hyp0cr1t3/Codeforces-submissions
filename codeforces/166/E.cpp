#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define MOD 1000000007  //1e9 + 7
#define pb push_back
const int N = 1e7 + 5;
typedef vector<vector<int> > matrix;
const int MATN = 2;

matrix mul(matrix A, matrix B) {
    matrix C(MATN+1, vector<int>(MATN+1));
    for (int i = 0; i < MATN; i++)
        for (int j = 0; j < MATN; j++)
            for (int k = 0; k < MATN; k++)
                C[i][j] = (int)((1ll * A[i][k] * B[k][j] % MOD + C[i][j]) % MOD);
    return C;
}

matrix pow(matrix A, int p) {
    if (p == 1)
        return A;
    if (p & 1)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int32_t main() {
    IOS;
    int i, n, ans;
    cin >> n;
    if (n == 1)
        return cout << 0, 0;
    if (n == 2)
        return cout << 3, 0;
    matrix A = {{2,3},{1,0}};
    A = pow(A, n-2);
    ans = (int)(3ll*A[0][0]%MOD);
    cout << ans;
    return 0;
}