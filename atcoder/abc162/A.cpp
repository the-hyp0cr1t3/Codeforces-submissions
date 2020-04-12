#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
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
#define pb emplace_back
#define sz(x) (int)(x).size()
#define MOD 1000000007  //1e9 + 7
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> T chmin(T &a, T b) { a = min(a, b); return a; }
template<class T> T chmax(T &a, T b) { a = max(a, b); return a; }
using pii = pair<int, int>;
using ll = long long;
const int N = 2e5 + 5;

int32_t main() {
    IOS;
    int i; string n;
    cin >> n;
    for(i = 0; i < sz(n); i++) 
        if(n[i] == '7') return cout << ("Yes"), 0;
    cout << ("No");
    return 0;
}
