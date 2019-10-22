#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    int q;
    cin >> q;
    while (q--){
        int n, i, p[205], val;
        bool flag = 1;
        pair<pair<int, int>, int> a[205];
        cin >> n;
        for(i = 1; i <= n; i++) {
            a[i].first.first = i;
            a[i].first.second = 1;
            cin >> val;
            a[i].second = p[i] = val;
        }
        while(flag) {
            flag = 0;
            for(i = 1; i <= n; i++) {
                if (a[i].first.first != a[i].second) {
                    flag = 1;
                    a[i].second = p[a[i].second];
                    a[i].first.second++;
                }
            }
        }
        for(i = 1; i <= n; i++)
            cout << a[i].first.second << " "; 
        cout << endl;
    }
    return 0;
}
