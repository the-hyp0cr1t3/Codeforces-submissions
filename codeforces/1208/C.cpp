#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
const int N = 1e3/2 + 2;
int q1[N][N], q2[N][N], q3[N][N], q4[N][N];
int32_t main() {
  IOS;
  int i, n, j, k = 0;
  cin >> n;
  for(i = 0; i < n/2; i++) {
    for(j = 0; j < n/2; j++, k++) {
      q1[i][j] = 4*k;
      q2[i][j] = 4*k+1;
      q3[i][j] = 4*k+2;
      q4[i][j] = 4*k+3;
    }
  }
  for(i = 0; i < n/2; i++) {
    for(j = 0; j < n/2; j++) 
      cout << q1[i][j] << " ";
    for(j = 0; j < n/2; j++) 
      cout << q2[i][j] << " ";
    cout << endl;
  }
  for(i = 0; i < n/2; i++) {
    for(j = 0; j < n/2; j++) 
      cout << q3[i][j] << " ";
    for(j = 0; j < n/2; j++) 
      cout << q4[i][j] << " ";
    cout << endl;
  }
  return 0;
}