// Author: πα

#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main()
{
    int n, i, j, m, a[501][501], flag = 0;
    long sum = 0;
    cin >> n >> m;
    for(i = 0; i<n; i++) {
        for(j = 0; j<m; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    
    for(i = n-2; i > 0; i--) {
        for(j = m-2; j > 0; j--) {
            if (!a[i][j]) {
                    flag = 1;
                    a[i][j] = min(a[i+1][j],a[i][j+1]) - 1;
                    sum += a[i][j];
//                    cout << a[i][j] << "\t";
            }
               
        }
    }

    for(i = 0; i<n; i++) {
        for(j = 0; j<m; j++) {
            if ((j != m-1 && i == n-1 && a[i][j] >= a[i][j+1]) || (j == m-1 && i != n-1 && a[i][j] >= a[i+1][j]) || (j != m-1 && i != n-1 && (a[i][j] >= a[i+1][j] || a[i][j] >= a[i][j+1]))) {
                cout << -1;
                return 0;
            }
 //            cout << "a[" << i << "][" << j << "] passed\n";
        }
    }
   
    cout << sum;
    return 0;
}
