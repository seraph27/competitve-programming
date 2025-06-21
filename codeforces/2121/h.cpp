// Problem: H. Ice Baby
// Contest: Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/contest/2121/problem/H
// Time Limit: 2000
// Start: 2025/06/20 11:20:50
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto &x : v) os << x << " "; return os;}

#ifdef MISAKA
struct _debug {
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
template<typename T> static void __print(const T &x) {
    if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
    else { cerr << '{'; int f{}; for (auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
}
template<typename T, typename V>
static void __print(const pair<T, V> &x) { cerr << '(', __print(x.first), cerr << ',', __print(x.second), cerr << ')'; }
template<typename T, typename... V>
static void _print(const T& t, const V&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ", ", _print(v...); else cerr << "]\n"; }
};
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else
#define debug(x...)
#endif


template<class T> struct segtree {
    struct Node {
        int sum, mx;
        Node(int s = 0, int m = 0) : sum(s), mx(m) {}
        friend Node operator+ (const Node &a, const Node &b) {
            return Node(a.sum + b.sum, max(a.mx, b.mx));
        }
    };
    const int N; vector<T> lazy, size;
    vector<Node> tree;
    segtree(int n) : N(1<<(__lg(n)+1)), tree(2*N), lazy(2*N), size(2*N) {
        for (int i = 0; i < n; i++) size[i+N] = 1;
        for (int i = N-1; i >= 1; i--) size[i] = size[i*2] + size[i*2+1];
    }
    void push(int node) {
        if (lazy[node]) {
            tree[node].sum += lazy[node] * size[node];
            tree[node].mx += lazy[node];
            if (node < N) lazy[node*2] += lazy[node], lazy[node*2+1] += lazy[node];
            lazy[node] = 0;
        }
    }
    void update(int node, int nl, int nr, int ql, int qr, T v) {
        push(node);
        if (ql > nr || qr < nl) return;
        if (ql <= nl && nr <= qr) {
            lazy[node] += v, push(node);
            return;
        }
        int mid = (nl+nr)/2;
        update(node*2, nl, mid, ql, qr, v);
        update(node*2+1, mid+1, nr, ql, qr, v);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    Node query(int node, int nl, int nr, int ql, int qr) {
        push(node);
        if (ql > nr || qr < nl) return Node();
        if (ql <= nl && nr <= qr) return tree[node];
        int mid = (nl+nr)/2;
        return query(node*2, nl, mid, ql, qr) + query(node*2+1, mid+1, nr, ql, qr);
    }
    void update(int l, int r, T v) { update(1, 0, N-1, l, r, v); }
    Node query(int l, int r) { return query(1, 0, N-1, l, r); }
};

void shiina_mashiro() {
    int n; cin >> n;
    vector<ar<int, 2>> segs(n);
    vector<int> vi;
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        segs[i] = {l, r};
        vi.pb(l); vi.pb(r);
    }
    sort_unique(vi);
    map<int, int> mp;
    for(int i = 0; i < sz(vi); i++) {
        mp[vi[i]] = i;
    }

    int MX = sz(vi);
    segtree<int> st(MX+1);
    for(int i = 0; i < n; i++) {
        for(int i = 0; i < MX-1; i++) {
            debug(i, st.query(i, i).sum, st.query(i, i).mx); 
        }
        int lb = mp[segs[i][0]], rb = mp[segs[i][1]];
        if(i == 0) {
            st.update(lb, lb, 1);
            cout << st.query(0, MX-1).mx << " ";
            continue;
        } 
        int lst = st.query(lb, rb).mx;
        int curr = st.query(0, lb).mx;
        int mxx = max(curr, lst) + 1;
        debug(lst, curr, mxx);
        st.update(lb, lb, mxx - st.query(lb, lb).mx);
        cout << st.query(0, MX-1).mx << " ";
    }
    cout << endl;
    //dp[i][j] := ith idx, last element is j, max length of longest non-decreasing subsequence

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

