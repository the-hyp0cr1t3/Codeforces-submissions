#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, i, j, k, freq[1001]={};
    vector<int> primes{2};    
    cin >> n >> k;
    for(i = 3; i <= n; i+=2) {
        if (!freq[i]) {
            primes.push_back(i);
            for(int q = 1; q < (int) primes.size(); q++) {
                if (i == primes[q] + primes[q-1] + 1)
                    k--;
            }
            for(j = i * i; j <= n; j+=2*i) {
                freq[j] = 1;
            }
        }
    }
   k > 0 ? cout << "NO" : cout << "YES";
    return 0;
}