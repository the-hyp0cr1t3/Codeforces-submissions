#include <bits/stdc++.h>
//#define long int64_t
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 1e8 + 7
#define INF 2e9
#define DESPACITO 1e18
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;
const int N = 105;

int main() {
    IOS
    int q;
    cin >> q;
    while (q--) {
        int n, i, j = 0, a[4*N], b[4*N];
        bool flag = 0;
        cin >> n;
        for(i = 0; i < 4 * n; i++)
            cin >> a[i];
        sort(a, a + 4 * n);
        ll area = a[0] * a[4*n-1];
        for(int l = 0, r = 4*n - 1; l < r; l+=2, r-=2) {
            if (a[l]!=a[l+1] or a[r]!=a[r-1] or a[l]*a[r]!=area) {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "NO" << endl;
        else            
            cout << "YES" << endl;
    }
    return 0;
}
