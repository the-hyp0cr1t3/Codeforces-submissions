#include <bits/stdc++.h>
#define cerr if(1)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define MOD 100000007  //1e8 + 7
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
#define PI acos(-1);
#define E 998244353
#define ins insert
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ll long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 1e5 + 5;

int main() {
    IOS;
    int i = 0;
    string s;
    cin >> s;
    if (s.front() == '@' or s.back() == '@')
        return cout << "No solution", 0;
    size_t f = s.find('@');
    if (f == string::npos)
        return cout << "No solution", 0;
    size_t next = s.find('@', f+1);
    while (next != string::npos) {
        if (next - f < 3)
            return cout << "No solution", 0;
        f = next;
        next = s.find('@', f+1);
    }
    f = s.find('@');
    while(f != string::npos) {
        while(i <= (int) f)
            cout << s[i++];
        f = s.find('@', f+1);
        if (f != string::npos)
            cout << s[i++] << ",";
    }
    while(i < (int) s.size())
        cout << s[i++];
    return 0;
}
