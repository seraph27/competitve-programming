// Problem: Mountain Range
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/3314
// Time Limit: 1000
// Start: Thu May 15 01:10:08 2025
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

#ifdef MISAKA
struct _debug {
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
template <class T>
struct segtree {
    const int N; vector<T> tree;
    segtree(int n) : N(1<<(__lg(n)+1)), tree(2*N) {}
    void update(int pos, T x) {
        for (int i = pos+N; i > 0; i >>= 1) ckmax(tree[i], x);
    }
    T query(int node, int nl, int nr, int ql, int qr) {
        if (ql > nr || qr < nl) return 0;
        if (ql <= nl && nr <= qr) return tree[node];
        int mid = (nl+nr)/2;
        return max(query(node*2, nl, mid, ql, qr), query(node*2+1, mid+1, nr, ql, qr));
    }
    T query(int l, int r) { return query(1, 0, N-1, l, r); }
};

const char nl = '\n';

void shiina_mashiro() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) 
        cin >> h[i];

    // parent[i] = index of parent of i in the Cartesian tree, or -1 if root
    vector<int> parent(n, -1);
    vector<int> stk;
    stk.reserve(n);

    // Build max‑Cartesian tree in O(n)
    for(int i = 0; i < n; i++){
        int last = -1;
        // Pop all smaller; the last one popped becomes left child of i
        while(!stk.empty() && h[stk.back()] < h[i]){
            last = stk.back();
            stk.pop_back();
        }
        if(last != -1){
            parent[last] = i;
        }
        if(!stk.empty()){
            parent[i] = stk.back();
        }
        stk.push_back(i);
    }

    // Build children lists
    vector<vector<int>> children(n);
    int root = -1;
    for(int i = 0; i < n; i++){
        if(parent[i] == -1) {
            root = i;
        } else {
            children[parent[i]].push_back(i);
        }
    }

    // BFS (or DFS) from root to compute depths
    int answer = 0;
    queue<pair<int,int>> q;
    q.emplace(root, 1);
    while(!q.empty()){
        auto [u, d] = q.front(); q.pop();
        answer = max(answer, d);
        for(int v: children[u]){
            q.emplace(v, d+1);
        }
    }

    cout << answer << "\n";   
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

