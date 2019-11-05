#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 100000007 //1e8 + 7
#define INF 2000000007
#define DESPACITO 1000000000000000000
#define PI acos(-1);
#define E 998244353
#define ins insert
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ll long long

using namespace std;
const int N = 5003;
int cache[N][N], c[N], n;

int dp (int l, int r) {
    while (c[l-1] == c[l] and l >= 1)
        l--;
    while (c[r+1] == c[r] and r <= n)
        r++;
    if (l <= 1 and r >= n)
        return 0;
    int &ans = cache[l][r];
    if (ans != -1)
        return ans;
    if (l == 1)
        ans = 1 + dp(l, r+1);
    else if (r == n)
        ans = 1 + dp(l-1, r);
    else if (c[l-1] == c[r+1])
        ans = 1 + dp(l-1, r+1);
    else
        ans = 1 + min(dp(l-1, r), dp(l, r+1));
    return ans;
}

int main() {
    IOS;
    int i;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for(i = 1; i <= n; i++) 
        cin >> c[i];
    int ans = INF;
    for(i = 1; i <= n; i++) 
        ans = min(ans, dp(i,i));
    cout << ans;
    return 0;
}
