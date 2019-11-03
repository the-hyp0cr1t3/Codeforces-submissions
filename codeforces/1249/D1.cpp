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
    int i, n, k, l, r, count = 0;
    map <int,set <pair<int, int>>> point;
    set <pair<int, int>> have;
    vector<int> toRemove;
    
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cin >> l >> r;
        point[l].insert({r+1, i});
        point[r+1].insert({-1, i});
    }
    for (auto& x: point) {
        for (auto& point_set: x.second) {
            if (point_set.first < 0)
                count--;
            else {
                count++;
                have.insert(point_set);
            }
        }
        while (count > k) {
            count--;
            pair<int, int> longest_segment = *have.rbegin();
            toRemove.pb(longest_segment.second);
            have.erase(longest_segment);
            point[longest_segment.first].erase({-1, longest_segment.second});
        }
    }
    cout << toRemove.size() << endl;
    for (auto& x: toRemove)
        cout << x << " ";
    return 0;
}
