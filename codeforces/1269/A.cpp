#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define ff first
#define ss second
#define rev(a) reverse(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins insert
#define pb push_back
#define sz(x) (int)(x).size()
#define MOD 1000000007  //1e9 + 7
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int, int> pii;
const int N = 1e8 + 5;
vector<bool> prime;

void sieve(int maxn) {
    int i, j;
    prime.assign(maxn+1, true);
    prime[0] = prime[1] = false;

    for(i = 2; i <= maxn; i+=2)
        prime[i] = i == 2;

    for(i = 3; i*i <= maxn; i+=2) 
        if (prime[i])
            for(j = i*i; j <= maxn; j+=i*2) 
                if (prime[j])
                    prime[j] = false;
}

int32_t main() {
    IOS;
    int i, n;
    cin >> n;
    sieve(N);
    for(i = 4; i <= N; i++) {
        if (!prime[i] and !prime[i+n]) break;
    }
    cout << i+n << " " << i;
    return 0;
}