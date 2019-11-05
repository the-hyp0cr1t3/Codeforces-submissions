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
const int N = 1e5 + 5;

int main() {
    int i, n;
    string a, b;
    cin >> n >> a >> b;
    vector<int> dp(n+1, 0);
    for(i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + (a[i-1] != b[i-1]);
        if (i > 1 and a[i-1] != a[i-2] and a[i-1] == b[i-2] and a[i-2] == b[i-1])
            dp[i] = dp[i-2] + 1;
    }
    cout << dp[n];
    return 0;
}
