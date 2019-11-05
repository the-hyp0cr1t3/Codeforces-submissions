#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 100000007 //1e8 + 7
#define INF 2e9
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
const int N = 1e5 + 5;

int main() {
    IOS;
    int i, n, dp[35];
    cin >> n;
    dp[0] = 1;
    for(i = 1; i <= 30; i++) 
        dp[i] = 2 * dp[i-1];
    if (n & 1)
        cout << 0;
    else
        cout << dp[n/2];
    return 0;
}
