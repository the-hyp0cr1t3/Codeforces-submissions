#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define INF 2000000000 //2e9
#define s second
#define f first
typedef pair<int, int> pii;
const int N = 103;
const int MAXA = 30;
const int MAXB = 59;
const int MAXP = 16;
const int MAXM = 1 << 16;
pii A[N];
int n, B[N], pMask[MAXB];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int dp[N][MAXM], path[N][MAXM];

void work() {
    int i, j, m;
    for(i = 2; i < MAXB; i++) {
        pMask[i] = 0;
        for(j = 0; j < MAXP; j++) 
            if (i % primes[j] == 0) pMask[i] |= (1 << j);
    }

    for(i = max(0, n-MAXP); i <= n; i++) {
        for(j = 0; j < MAXM; j++) 
            dp[i][j] = INF;
    }
    for(i = 0; i < n-MAXP; i++) 
        dp[i+1][0] = dp[i][0] + A[i].f - 1, path[i+1][0] = 1;
    dp[0][0] = 0;
}

void _dp() {
    int i, j, b;
    for(i = max(0, n-MAXP); i < n; i++) {
        for(j = 0; j < MAXM; j++) {
            if (dp[i][j] == INF) continue;
            for(b = 1; b < MAXB; b++) {
                if (!(j & pMask[b])) {
                    int t = dp[i][j] + abs(A[i].f - b);
                    if (t < dp[i+1][j | pMask[b]])
                        dp[i+1][j | pMask[b]] = t, path[i+1][j | pMask[b]] = b;
                }
            }
        }
    }
}

void _path() {
    int idx, j, m = 0, ans = dp[n][0];
    for(j = 0; j < MAXM; j++) 
        if (dp[n][j] < ans)
            ans = dp[n][j], m = j;
    idx = n;
    while (idx) {
        int p = path[idx][m];
        B[A[idx-1].s] = p;
        m -= pMask[p];
        idx--;
    }
}

int32_t main() {
    IOS;
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> A[i].f, A[i].s = i;
    sort(A, A+n);
    work();
    _dp();
    _path();
    for(int i = 0; i < n; i++) 
        cout << B[i] << " ";
    return 0;
}