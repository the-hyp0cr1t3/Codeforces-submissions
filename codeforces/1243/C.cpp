#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 100000007  //1e8 + 7
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
#define PI acos(-1);
#define E 998244353
#define ins insert
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define int long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 1e5 + 5;
map<int, int> factorize(int x)
{
    int n = x;
    map<int, int> m;
    for(int i = 2; i*i <= n and x > 1; ++i)
        while(x % i == 0)
            m[i]++, x /= i;
    if(x > 1)
        m[x]++;
    return m;
}


int32_t main() {
    IOS;
    int i, n, ans;
    cin >> n;
    map <int,int> m = factorize(n);
    int sz = (int)m.size();
    if (m[n] and m.size()==1)
        ans = n;
    else if (!m[n]) {
        if (sz > 1)
            ans = 1;
        else {
            for (auto& [k, v]: m) {
                ans = n;
                for(i = 0; i < v-1; i++) 
                    ans /= k;
                break;
            }
        }
    }
    else {
        if (sz > 2)
            ans = 1;
        else {
            for (auto& [k, v]: m) {
                ans = n;
                for(i = 0; i < v; i++) 
                    ans /= k;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
