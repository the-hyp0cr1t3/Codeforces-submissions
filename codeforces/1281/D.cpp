#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int r, c, i, j;
        char ch;
        cin >> r >> c;
        bool flag = 0, flag3 = 0, flag2 = 0, flag1 = 0, flag0 = 1;
        vector<vector<bool>> mat(r, vector<bool>(c));
        for(i = 0; i < r; i++) {
            int rowcnt = 0;
            for(j = 0; j < c; j++) {
                cin >> ch;
                if (ch == 'A') {
                    mat[i][j] = 1, flag = 1, rowcnt++;
                    if ((i == 0 or i == r-1) and (j == 0 or j == c-1)) flag2 = 1;
                    if ((i == 0 or i == r-1) or (j == 0 or j == c-1)) flag3 = 1;
                }
                else
                    flag0 = 0;
            }
            if (rowcnt == c) {
                if (i == 0 or i == r-1) flag1 = 1;
                else flag2 = 1; 
            }
        }
        for(j = 0; j < c; j++) {
            int colcnt = 0;
            for(i = 0; i < r; i++)
                if (mat[i][j]) colcnt++;
            if (colcnt == r) {
                if (j == 0 or j == c-1) flag1 = 1;
                else flag2 = 1; 
            }
        }
        if (!flag) cout << "MORTAL" << endl;
        else if (flag0) cout << 0 << endl;
        else if (flag1) cout << 1 << endl;
        else if (flag2) cout << 2 << endl;
        else if (flag3) cout << 3 << endl;
        else cout << 4 << endl;
    }
    return 0;
}