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
const int N = 1e5 + 5;

int main() {
    int i, n, a[2 * N], k = 1;
    cin >> n;
    if ((n+1) & 1) {
        cout << "NO";
        return 0;
    }
    else 
        cout << "YES" << endl;
    for(i = 1; i <= n; i+=2) {
        a[i] = k++;
        a[n+i] = k++;
        a[n+i+1] = k++;
        if (i < n)
            a[i+1] = k++;
    }
    for (i = 1; i <= 2 * n; i++)
        cout << a[i] << " ";
    return 0;
}
