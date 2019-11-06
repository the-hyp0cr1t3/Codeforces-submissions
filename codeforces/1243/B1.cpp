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
#define ll long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 1e5 + 5;

int main() {
    IOS;
    int q;
    cin >> q;
    while (q--) {
        int n, i, cnt = 0;
        bool flag = 0;
        string s, t;
        char s1, s2, t1, t2;
        cin >> n >> s >> t;
        for(i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                cnt++;
                if (cnt > 2) {
                    flag = 1;
                    break;
                }
                if (cnt == 1) 
                    s1 = s[i], t1 = t[i];
                else
                    s2 = s[i], t2 = t[i];
            }
        }
        if (flag or cnt == 1) {
            cout << "No" << endl;
            continue;
        }
        if (!cnt) {
            cout << "Yes" << endl;
            continue;
        }
        if (s1 == s2 and t1 == t2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
