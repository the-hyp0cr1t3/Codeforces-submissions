#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, k;
map <int,int> cnt;

void query(int skip) {
    int p, pos;
    cout << "?";
    for(int i = 1; i <= k+1; i++) {
        if (i == skip) continue;
        cout << " " << i;
    }
    cout << endl;
    cin >> pos >> p;
    cnt[p]++;
}

int32_t main() {
    IOS;
    int i;
    cin >> n >> k;
    for(i = 1; i <= k+1; i++) 
        query(i);
    cout << "! " << cnt.rbegin()->second << endl;
    return 0;
}