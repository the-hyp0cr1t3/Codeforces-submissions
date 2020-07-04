/**
 *  the_hyp0cr1t3
 *  04.07.2020 14:01:09
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
template<class T> class Y {
    T f_;
public:
    template<class U> explicit Y(U&& f): f_(forward<U>(f)) {}
    template<class ...Args> decltype(auto) operator()(Args&&... args) {
        return f_(ref(*this), forward<Args>(args)...);
    }
}; 
template<class T> Y(T) -> Y<T>;

const int N = 2e5 + 5;

int32_t main() {
    IOS;
    int i, n, k, A, B;
    re(n, k, A, B);
    vector<int> v(k); re(v);
    sort(all(v));

    auto solve = Y([&](auto self, int l, int r) -> int {
        int cnt = upper_bound(all(v), r) - lower_bound(all(v), l);
        if(!cnt) return A;
        if(l == r) return B * cnt;
        int mid = l + r >> 1;
        return min(B * (r-l+1) * cnt, self(l, mid) + self(mid+1, r));
    });

    ps(solve(1, 1<<n));
    return 0;
}

/**
    Lowk But don'e touco

**/