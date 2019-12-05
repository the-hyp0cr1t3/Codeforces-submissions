#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define pb push_back
vector<int>  cnt(4), rem(4), ans;
int32_t main() {
    IOS;
    int i, n, start, cur = 0, y = 0;
    for(i = 0; i < 4; i++) 
        cin >> cnt[i];
    for(start = 0; start < 4; start++, cur = start) {
        rem = cnt;
        if (!rem[cur])
            continue;
        while(true) {
            rem[cur]--;
            ans.pb(cur);
            if (cur < 3 and (rem[cur]+1 > 0) and rem[cur+1])
                cur++;
            else if (cur and (rem[cur]+1 > 0) and rem[cur-1])
                cur--;
            else
                break;
        }
        if (!rem[0] and !rem[1] and !rem[2] and !rem[3]) {
            cout << "YES" << endl;
            for (auto& x: ans) 
                cout << x << " ";
            return 0;
        }
        else
            ans.clear();
    }
    cout << "NO";
    return 0;
}