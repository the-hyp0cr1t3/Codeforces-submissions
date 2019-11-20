#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int N = 1e5 + 5;
int n, k, pref[N];

bool check(int x) {
    for(int i = 0; i <= n-x; i++) {
        int a = pref[i+x] - pref[i];
        int b = x - a;
        if (a <= k or b <= k)
            return 1;
    }
    return 0;
}

int binarySearch(int low, int high) {
    while(low <= high) {
        int mid = (high + low) / 2;
        if(check(mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high; 
}

int32_t main() {
    IOS;
    int i, ans = 0;
    string s;
    cin >> n >> k >> s;
    for(i = 1; i <= n; i++) 
        pref[i] = pref[i-1] + (s[i-1] == 'a');
    cout << binarySearch(1, n);
    return 0;
}