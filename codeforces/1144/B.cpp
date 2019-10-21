#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, i, a;
    long sum1 = 0, sum2 = 0;
    cin >> n;
    multiset <int> se, so;
    for(i = 0; i < n; i++) {
        cin >> a;
        a & 1 ? so.insert(a) : se.insert(a);
    }
    multiset<int>::iterator ite = se.begin(), ito = so.begin();
    if (so.size() < se.size())
        for(int j = 0; j < (int) (se.size() - so.size()) - 1 and ite != se.end(); ite++, j++)
            sum1 += *ite;
    if (so.size() > se.size())
        for(int j = 0; j < (int) (so.size() - se.size()) - 1 and ito != so.end(); ito++, j++)
            sum2 += *ito;
//    cout << sum1 << " " << sum2 << " \n";
    cout << max(sum1, sum2);
    return 0;
}
