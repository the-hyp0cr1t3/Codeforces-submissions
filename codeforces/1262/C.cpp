#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
typedef pair<int, int> pii;
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
      int n, i, j, k, cnt = 0;
      vector<pii> ans;
      string s, t;
      cin >> n >> k >> s;
      for (i = 0; i < k-1; i++)
        t += "()";
      for(i = 0; i < 2*(n/2 - k + 1); i++) 
        t += "()"[i>n/2-k];
      for(i = 0; i < n; i++) {
        for(j = i; j < n; j++) {
          if (s[j] == t[i]) {
            ans.push_back({i+1, j+1});
            cnt++;
            reverse(s.begin()+i, s.begin()+j+1);
            break;
          }
        }
      }
      cout << cnt << endl;
      for (auto& x: ans) 
          cout << x.first << " " << x.second << endl;
    }
    return 0;
}