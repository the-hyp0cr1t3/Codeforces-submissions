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
const int N = 55;
int n;
string s, t;

int main() {
    IOS;
    int q;
    cin >> q;
    while (q--) {
        vector<pair<int, int>> ans;
        int i, freq[28] = {}, swap1pos, swap2pos;
        bool flag = 0;
        cin >> n >> s >> t;
        for(i = 0; i < n; i++) 
            freq[s[i]-'a']++, freq[t[i]-'a']++;
        for(i = 0; i < 26; i++) {
            if (freq[i] & 1) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "No" << endl;
            continue;
        }
        for(i = 0; i < n - 1; i++) {
            swap1pos = swap2pos = -1;
            if (s[i] == t[i])
                continue;
            for(int j = i+1; j < n; j++) {
                if (s[j] == s[i]) {
                    swap1pos = j;
                    break;
                }
                if (t[j] == s[i])
                    swap2pos = j;
            }
            if (swap1pos != -1)
                swap(t[i], s[swap1pos]), ans.pb(mp(swap1pos+1, i+1));
            else {
                swap(s[swap2pos],t[swap2pos]);
                ans.pb(mp(swap2pos+1, swap2pos+1));
                swap(t[i], s[swap2pos]);
                ans.pb(mp(swap2pos+1, i+1));
            }
        }
        cout << "Yes" << endl << ans.size() << endl;
        for (auto& x: ans)
            cout << x.first << " " << x.second << endl;
    }
    return 0;
}
