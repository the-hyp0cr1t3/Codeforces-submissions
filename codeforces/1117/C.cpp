#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 1e8 + 7
#define INF 1000000000000000000000000
#define DESPACITO 1e18
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
#define ll long long
const int N = 1e5 + 5;

pair <int, int> day[N];
ll n, xdiff, ydiff;

bool check (ll k) {
    ll x, y;
    x = day[n].first * (k/n) + day[k % n].first;
    y = day[n].second * (k/n) + day[k % n].second;
    return abs(xdiff - x) + abs(ydiff - y) > k;
}

ll binarySearch(ll low, ll high) {
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(check(mid))
            low = mid + 1;
        else
            high = mid - 1; 
    }
    return low;
}

int main() {
    int i, x1, y1, x2, y2;
    string s;
    cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
    xdiff = x2 - x1;
    ydiff = y2 - y1;
    day[0] = mp(0,0);
    for(i = 1; i <= n; i++) {
        day[i] = day[i-1];
        switch(s[i-1]){
            case 'U': day[i].second++; break;
            case 'D': day[i].second--; break;
            case 'L': day[i].first--; break;
            case 'R': day[i].first++; break;
        }
    }
    ll ans = binarySearch(1ll, (ll)INF);
    cout << (ans <= INF? ans : -1);
    return 0;
}
