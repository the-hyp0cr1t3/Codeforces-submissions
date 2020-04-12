#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
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
const int N = 4e3 + 5;
int l[N][3], r[N][3];
int32_t main() {
    IOS;
    int i, j, k, n, ans = 0; string s;
    cin >> n >> s;
    s = '#' + s;
    auto val = [] (char c) {
        return c == 'R'? 0 : c == 'G'? 1 : 2;
    };

    for(i = 1; i <= n; i++) {
        l[i+1][val(s[i])]++;
        for(j = 0; j < 3; j++) 
            l[i][j] += l[i-1][j];
    }

    for(i = n; i; i--) {
        r[i-1][val(s[i])]++;
        for(j = 0; j < 3; j++) 
            r[i][j] += r[i+1][j];
    }

    for(int mid = 1; mid <= n; mid++) {
        for(i = 0; i < 3; i++) {
            if(i != val(s[mid])) continue;
            for(j = 0; j < 3; j++) {
                if(i == j) continue;
                for(k = 0; k < 3; k++) {
                    if(k == j or k == i) continue;
                    ans += l[mid][j] * r[mid][k];
                }
            }
        }       
    }

    for(i = 1; i <= n; i++) {
        for(j = i+1; j <= n; j++) {
            if(s[i] == s[j] or j-i+j > n) continue;
            k = j-i+j;
            if(s[i] != s[k] and s[j] != s[k]) ans--;
        }
    }
    
    cout << ans;
    return 0;
}