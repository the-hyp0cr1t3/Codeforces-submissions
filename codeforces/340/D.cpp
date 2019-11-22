#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define pb push_back
const int N = 1e5 + 5;

int n, a[N];
vector<int> lis;

bool check (int y, int search) {
    if (a[lis[y]] <= search)
        return 1;
    else
        return 0;
}

int binarySearch(int low, int high, int search) {
    while(low < high) {
        int mid = (low + high) / 2;
        if(check(mid, search))
            low = mid + 1;
        else
            high = mid;
    }
    return low; 
}

int LIS() {
    int i, len = 0;
    for(i = 0; i < n; i++) {
        int x = binarySearch(0, len, a[i]);
        if (x == len)
            lis.pb(i), len++;
        else
            lis[x] = i;
    }
    return len;
}

int32_t main() {
    IOS;
    int i;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    cout << LIS();
    return 0;
}