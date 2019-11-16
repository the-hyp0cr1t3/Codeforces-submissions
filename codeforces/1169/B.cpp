#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 3e5 + 5;
int a[N], b[N], m;

bool check (int x, int y) {
  for(int i = 1; i <= m; i++) {
    if (a[i]==x || a[i]==y || b[i]==x || b[i]==y) continue;
    if (y) return 0;
    return (check(a[i], x) || check(b[i], x));
  }
  return 1;
}

int32_t main() {
  IOS;
  int i, n;
  cin >> n >> m;
  for(i = 1; i <= m; i++) 
    cin >> a[i] >> b[i];
  if (check(a[0], 0) or check(b[0], 0))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
