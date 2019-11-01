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
const int N = 100 + 5;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i, k, h[N];
        bool flag = 0;
        ll m;
        cin >> n >> m >> k;
        for(i = 0; i < n; i++)
            cin >> h[i];
        for(i = 0; i < n - 1; i++) {
            if (h[i] > h[i+1] - k)
                m += h[i] - max(h[i+1] - k, 0);
            else {
                if (h[i+1] - k <= h[i] + m)
                    m -= max(h[i+1] - k, 0) - h[i];
                else {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}