#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, i, freq[] = {0, 0, 0, 0, 0}, a, count = 0;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a;
        freq[a]++;
    }
    
    count += freq[4];
    
    if (freq[2] & 1) {
        count += (freq[2] - 1)/2;
        freq[2] = 1;
    }
    else {
        count += freq[2]/2;
        freq[2] = 0;
    }

    if (freq[3] >= freq[1]){
        count += freq[3] + freq[2];
    }
    else {
        count += freq[3];
        freq[1] -= freq[3]; 
        if (freq[1] < 3)
            count++;
        else{
            count++;
            freq[1] -= freq[2]? 2: 4;
            count += freq[1]/4 + (freq[1]%4 ? 1 : 0);
        }
    }
    cout << count;
    return 0;
}
