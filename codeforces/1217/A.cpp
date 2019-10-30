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
int str, intel, xp;

bool check(int x) {
    return ((str + x) > (intel + xp - x));
}

int binarySearch(int low, int high) {
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low; 
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int i;
        cin >> str >> intel >> xp;
        cout << xp - binarySearch(0, xp) + 1<< endl;
    }
    return 0;
}
