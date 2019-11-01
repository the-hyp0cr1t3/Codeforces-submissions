#include <bits/stdc++.h>
//#define long int64_t
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 1e8 + 7
#define INF 2e9
#define DESPACITO 1e18
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;
const int N = 1e5 + 5;
string s, t = "abcdefghijklmnopqrstuvwxyz";

int binarySearch(int low, int high, char key) {
    while(low <= high) {
        int mid = (low + high) / 2;
        if((int) key > (int) t[mid])
            low = mid + 1;
        else if ((int) key < (int) t[mid])
            high = mid - 1;
        else
            return mid;
    }
    return -1; 
}


int main() {
    int i, j;
    cin >> s;
    for(i = 0; i < (int) s.length(); i++) {
        int x = binarySearch(0, (int) t.length() - 1, s[i]);
        if (x == -1)
            cout << "Ann" << endl;
        else {
            t.erase(x+1);
            cout << "Mike" << endl;
        }
    }
    
    return 0;
}