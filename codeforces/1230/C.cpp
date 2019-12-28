#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 8;
bool taken[N][N];

int32_t main() {
    IOS;
    int i, j, k, n, m, ans = 42069;
    cin >> n >> m;
    if (n < 7) return cout << m, 0;
    for(i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        taken[u][v] = taken[v][u] = 1;
    }
    for(i = 1; i < N; i++) {
        for(j = i+1; j < N; j++) {
            int cnt = 0;
            for(k = 1; k < N; k++) 
                if (taken[i][k] and taken[j][k]) cnt++;
            ans = min(ans, cnt);
        }
    }
    cout << m - ans;
    return 0;
}