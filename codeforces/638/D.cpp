#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 100 + 5;
int a[N][N][N];
int32_t main() {
    IOS;
    int x, y, z, n, m, K, ans = 0;
    char c;
    cin >> n >> m >> K;
    for(x = 1; x <= n; x++)
        for(y = 1; y <= m; y++)
            for(z = 1; z <= K; z++)
                cin >> c, a[x][y][z] = c-'0';
    auto check = [&] () {
        int i, j, k;
        if (!a[x][y][z]) return false;

        if (a[x-1][y][z] and a[x+1][y][z]) return true;
        if (a[x][y-1][z] and a[x][y+1][z]) return true;
        if (a[x][y][z-1] and a[x][y][z+1]) return true;

        if (a[x-1][y][z] and a[x][y+1][z] and !a[x-1][y+1][z]) return true;
        if (a[x][y-1][z] and a[x+1][y][z] and !a[x+1][y-1][z]) return true;

        if (a[x-1][y][z] and a[x][y][z+1] and !a[x-1][y][z+1]) return true;
        if (a[x][y][z-1] and a[x+1][y][z] and !a[x+1][y][z-1]) return true;

        if (a[x][y-1][z] and a[x][y][z+1] and !a[x][y-1][z+1]) return true;
        if (a[x][y][z-1] and a[x][y+1][z] and !a[x][y+1][z-1]) return true;

        return false;
    };
    for(x = 1; x <= n; x++)
        for(y = 1; y <= m; y++)
            for(z = 1; z <= K; z++)
                ans += check();
    cout << ans;
    return 0;
}