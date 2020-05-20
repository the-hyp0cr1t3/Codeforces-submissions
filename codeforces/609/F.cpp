#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;
#define endl "\n"
#define ff first
#define ss second
#define all(Aa) Aa.begin(),Aa.end()
#define lb lower_bound
#define rsz resize
#define ins insert
#define mp make_pair
using pii = pair<int, int>;
const int DESPACITO = 1000000000000000000;  //1e18
struct Data {
    int tongue, cnt;
    Data() : tongue(-1), cnt(0) {};
};
struct Mosquito {
    int pos, siz, id;
    Mosquito(int p, int s, int i) : pos(p), siz(s), id(i) {};
};
auto cmp = [] (const Mosquito& A, const Mosquito& B) {
    if(A.pos == B.pos) return A.id < B.id;
    return A.pos < B.pos;
};
set<Mosquito, decltype(cmp)> pending(cmp);
vector<pair<pii, int>> frogs;

struct SegTree {
    int N, curpending = 0;
    vector<Data> st;
    vector<pii> res;

    void merge(Data &cur, Data &l, Data &r) {
        cur.tongue = max(l.tongue, r.tongue);
    }

    void build(int node, int L, int R) {
        if(L == R) {
            st[node].tongue = frogs[L-1].ff.ff + frogs[L-1].ff.ss;
            return;
        }
        int M = (L+R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        merge(st[node], st[node*2], st[node*2+1]);
    }

    SegTree(int n) : N(n) {
        st.rsz(4*n + 5);
        res.rsz(n);
    }

    void Query(int node, int L, int R) {
        if(L == R) {
            res[frogs[L-1].ss] = mp(st[node].cnt, st[node].tongue-frogs[L-1].ff.ff);
            return;
        }
        int M = (L + R)/2;
        Query(node*2, L, M);
        Query(node*2 + 1, M + 1, R);
    } 

    bool Update(int node, int L, int R, Mosquito mosquito) {
        if(L == R) {
            if(frogs[L-1].ff.ff > mosquito.pos)
                return false;
            if(st[node].tongue < mosquito.pos)
                return false;
            st[node].tongue += mosquito.siz;
            st[node].cnt++;
            Mosquito search(frogs[L-1].ff.ff, -1, -1);
            auto it = pending.lb(search);
            auto it2 = it;
            while(it2 != pending.end() and it2->pos <= st[node].tongue) {
                st[node].tongue += it2->siz;
                st[node].cnt++;
                it2++;
            }
            st[node].tongue = st[node].tongue;
            pending.erase(it, it2);
            return true;
        }
        if(st[node].tongue < mosquito.pos)
            return false;
        int M = (L + R)/2;
        bool ret = 0;
        if(st[node*2].tongue >= mosquito.pos)
            ret = Update(node*2, L, M, mosquito);
        else
            ret = Update(node*2 + 1, M + 1, R, mosquito);
        merge(st[node], st[node*2], st[node*2 + 1]);
        return ret;
    }

    vector<pii> query() {
        Query(1, 1, N);
        return res;
    }

    void update(Mosquito mosquito) {
        if(!Update(1, 1, N, mosquito))
            pending.ins(mosquito);
    }

};

int32_t main() {
    IOS;
    int i, n, m;
    cin >> n >> m; frogs.rsz(n);
    for(i = 0; i < n; i++) 
        cin >> frogs[i].ff.ff >> frogs[i].ff.ss, frogs[i].ss = i;
    sort(all(frogs));
    SegTree st(n);
    st.build(1, 1, n);
    for(i = 0; i < m; i++) {
        int _p, _sz; cin >> _p >> _sz;
        Mosquito mosquito(_p, _sz, i);
        st.update(mosquito);
    }
    auto ans = st.query();
    for(auto& [x, y]: ans) 
        cout << x << " " << y << endl;
    return 0;
}