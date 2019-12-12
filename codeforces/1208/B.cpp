#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define sz(x) (int)(x).size()
const int N = 2e3 + 5;
int a[N], n;

bool check (int x) {
    int i;
    map <int,int> mp;
    for(i = 1; i <= n; i++) 
        mp[a[i]]++;
    for(i = 1; i <= x; i++) {
        mp[a[i]]--;
        if (!mp[a[i]]) mp.erase(a[i]);
    }
    if (n-x == sz(mp)) return 1;
    for(i = 1; i <= n-x; i++) {
        mp[a[i]]++;
        mp[a[i+x]]--;
        if (!mp[a[i+x]]) mp.erase(a[i+x]);
        if (n-x == sz(mp)) return 1;
    }
    return 0;
}

int binarySearch(int low, int high) {
    while(low <= high) {
        int mid = (low + high) / 2;
        if(!check(mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low; 
}

int32_t main() {
    IOS;
    int i;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    int x = binarySearch(0, n);
    cout << x;
    return 0;
}