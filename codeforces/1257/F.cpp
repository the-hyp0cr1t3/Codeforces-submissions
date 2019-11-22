#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define pb push_back
const int N = 100 + 5;
int a[N];
map <vector<int>,int> righthalf; 
int32_t main() {
    IOS;
    int i, j, n;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    for(i = 0; i < (1<<15); i++) {
        vector<int> cur;
        for(j = 0; j < n; j++) 
            cur.pb(__builtin_popcount((a[j]^i)%(1<<15)));
        righthalf[cur] = i;
    }
    for(i = 0; i < (1<<15); i++) {
        vector<int> cur;
        for(j = 0; j < n; j++) 
            cur.pb(-__builtin_popcount((a[j]>>15)^i));
        for(j = 0; j <= 30; j++) {
            if (righthalf.count(cur))
                return cout << (righthalf[cur] | i<<15), 0;
            for(int k = 0; k < n; k++) 
                cur[k]++;
        }
    }
    cout << -1;
    return 0;
}