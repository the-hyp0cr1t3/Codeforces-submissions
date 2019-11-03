#include <bits/stdc++.h>
//#define long int64_t
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
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
const int N = 1e3 + 5;

int main() {
    int i, n, m, a[N], ans = 0;
    char c;
    int freq[N][5];
    memset(freq, 0, sizeof(freq));
    cin >> n >> m;
    for(i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c;
            freq[j][c - 'A']++;
        }
    }
    for(i = 0; i < m; i++) 
        cin >> a[i];
    for(i = 0; i < m; i++) {
        int max = 0;
        for(int j = 0; j < 5; j++)
            max = max(max, freq[i][j]);
        ans += max * a[i];
    }
    cout << ans;
    return 0;
}
