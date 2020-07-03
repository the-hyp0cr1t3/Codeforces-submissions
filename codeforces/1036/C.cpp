/**
 *  the_hyp0cr1t3
 *  03.07.2020 22:43:45
**/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define rev(Aa) reverse(Aa.begin(),Aa.end())
#define all(Aa) Aa.begin(),Aa.end()
#define ins insert
#define mp make_pair
#define pb emplace_back
#define sz(Xx) (int)(Xx).size()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll DESPACITO = 1e18;

template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) { is >> p.first >> p.second; return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for(auto& x: v) is >> x; return is; }
auto re = [](auto&&... args) { (cin >> ... >> args); };
auto rea = [](auto&& A, auto sz_) { for(int i = 0; i < sz_; i++) cin >> A[i]; };
auto chmax = [](auto& A, auto&& B) { A = max(A, B); };
auto chmin = [](auto& A, auto&& B) { A = min(A, B); };
char delim = ' ';
template<class T1, class T2> ostream& operator<<(ostream& os, pair<T1,T2>& p) { os << p.first << ' ' << p.second; return os; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { if(v.size()) { os << v[0]; for(int i = 1; i < (int)v.size(); i++) os << delim << v[i]; } return os; }
auto pr = [](auto&& arg, auto&&... args) { cout << arg; ((cout << "" << args), ...); };
auto pw = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << ' '; };
auto ps = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << endl; };
auto pc = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ", " << args), ...); cout << ']' << endl; };
auto pnv = [](auto&& arg) { for(auto& v: arg) { cout << v; cout << endl; } };
auto pn = [](auto&& arg, auto&&... args) { delim = '\n'; cout << arg; ((cout << endl << args), ...); cout << endl; delim = ' '; };
auto ptrace = [](auto&& arg, auto&&... args) { cout << '[' << arg; ((cout << "][" << args), ...); cout << ']'; };
#define tr(args...) pr('[', #args, "] = ["), pc(args);
#define tra(arg, args...) __f(#arg, arg, args)
template<class arg, class ...args> void __f(const char* name, arg&& A, args&&... rest) { 
    const char* open = strchr(name, '['); cout.write(name, open-name); 
    ptrace(rest...); cout << " = " << A << endl;
}

const int N = 2e5 + 5;

int solve () {
    int i, j, k, l, r; string a, b;
    re(l, r); l--;
    auto to_string = [](int x) {
        stringstream ss;
        ss << x;
        string y;
        ss >> y;
        return y;
    };
    a = to_string(l);
    b = to_string(r);

    auto calc = [&](string s) {
        rev(s);
        int len = sz(s);
        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(2, vector<int>(4)));
        dp[0][0][0] = dp[0][1][0] = 1;
        for(i = 1; i <= len; i++) {
            for(k = 0; k < 4; k++) {
                dp[i][0][k] += dp[i-1][0][k];
                dp[i][1][k] += dp[i-1][s[i-1] == '0'][k];
            }
            for(j = 1; j < 10; j++) {
                for(k = 0; k < 3; k++) 
                    dp[i][0][k+1] += dp[i-1][0][k];
                if(j <= s[i-1]-'0')
                    for(k = 0; k < 3; k++) 
                        dp[i][1][k+1] += dp[i-1][j == s[i-1]-'0'][k];
            }
        }
        int ans = 0;
        for(i = 0; i < 4; i++) 
            ans += dp[len][1][i];
        return ans;
    };

    ps(calc(b)-calc(a));
    return 0;
}

int32_t main() {
    IOS;
    int Q;
    for(cin >> Q; Q; Q--)
        solve();
    return 0;
}

/**
    LohC but don't tJoch

**/