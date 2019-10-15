#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, a, i, k, count = 0, flag = 0, kval;
    cin >> n >> k;
    for(i = 0; i < n; i++) {
        cin >> a;
        if (flag) {
            if (a == kval)
                count++;
            else
                break;
        }
        else {
            if (a > 0) 
                count++;
            else
                break;
        }
        if (i==k-1) {
            flag++;
            kval = a;
        }
    }
    cout << count;
    return 0;
}
