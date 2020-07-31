/**
 🍪 the_hyp0cr1t3
 🍪 01.08.2020 00:35:27
**/
#include <bits/stdc++.h>
// #define int long long
#define k_II ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DubYu return 0;
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

#ifdef LOCAL
bool loc = true;
#define tr(...) pr("(", __LINE__, ")[", #__VA_ARGS__, "]: ["), pc(__VA_ARGS__)
#define tra(arg, args...) ptrace(#arg, arg, args)
#else
bool loc = false;
#define tr(...) "🍪"
#define tra(...) "🍪"
#endif

template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) { is >> p.first >> p.second; return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for(auto& x: v) is >> x; return is; }
auto re = [](auto&&... args) { (cin >> ... >> args); };
auto rea = [](auto&& A, auto sz_) { for(int i = 0; i < sz_; i++) cin >> A[i]; };
auto chmax = [](auto& A, auto&& B) { A = max(A, B); };
auto chmin = [](auto& A, auto&& B) { A = min(A, B); };
auto isLOC = [](auto A, string B = "") { return loc? A : B; };
template<class T1, class T2> ostream& operator<<(ostream& os, pair<T1,T2> p) 
{ os << isLOC("(") << p.first << isLOC(", ", " ") << p.second << isLOC(")"); return os; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { bool fst = 1; os << isLOC("{"); for(auto& x: v) 
{ if(!fst) os << isLOC(", ", " "); os << x; fst = 0; } os << isLOC("}"); return os; }
template<class T> ostream& operator<<(ostream& os, set<T>& v) { bool fst = 1; os << isLOC("{"); for(auto& x: v) 
{ if(!fst) os << isLOC(", ", " "); os << x; fst = 0; } os << isLOC("}"); return os; }
template<class T1, class T2> ostream& operator<<(ostream& os, map<T1,T2>& v) { bool fst = 1; os << isLOC("{"); for(auto& [x, y]: v)
{ if(!fst) os << isLOC(", ", " "); os << x << isLOC(": ", " ") << y; fst = 0; } os << isLOC("}"); return os; }
auto pr = [](auto&& arg, auto&&... args) { cout << arg; ((cout << "" << args), ...); };
auto pw = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << ' '; };
auto ps = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ' ' << args), ...); cout << endl; };
auto pc = [](auto&& arg, auto&&... args) { cout << arg; ((cout << ", " << args), ...); cout << ']' << endl; };
auto pnv = [](auto&& arg) { for(auto& v: arg) { cout << v; cout << endl; } };
auto ptrace = [](const char* name, auto&& A, auto&&... rest) {
    const char* open = strchr(name, '['); cout.write(name, open-name);
    ((cout << '[' << rest << ']'), ...); cout << " = " << A << endl;
};

const int N = 2e5 + 5;
string s;

struct Data {
    int left, right;
    Data() : left(0), right(0) {}

    void init(int idx) {
        if(s[idx-1] == '(') right = 1;
        else left = 1;
    }

    void merge(const Data& l, const Data& r) {
        int take = min(l.right, r.left);
        left = l.left + r.left - take;
        right = r.right + l.right - take;
    }
};

struct SegTree {
    int N;
    vector<Data> st;

    void build(int node, int L, int R) {
        if(L == R) {
            st[node].init(L);
            return;
        }
        int M = (L+R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        st[node].merge(st[node*2], st[node*2+1]);
    }

    SegTree(int n) : N(n) {
        st.resize(4*n + 5);
    }

    Data Query(int node, int L, int R, int i, int j) {
        if(i > R or j < L)
            return Data();
        if(i <= L and j >= R)
            return st[node];
        int M = (L + R)/2;
        Data left = Query(node*2, L, M, i, j);
        Data right = Query(node*2 + 1, M + 1, R, i, j);
        Data cur; cur.merge(left, right);
        return cur;
    }

    int query(int l, int r) {
        auto q = Query(1, 1, N, l, r);
        return r-l+1-q.left-q.right;
    }

};

int32_t main() {
    k_II
    re(s);
    SegTree st(sz(s));
    st.build(1, 1, sz(s));
    
    int Q; re(Q);
    while(Q--) {
        int l, r; re(l, r);
        ps(st.query(l, r));
    }

    DubYu
}

/**
    Nsw leveTs, new EeDilR

**/