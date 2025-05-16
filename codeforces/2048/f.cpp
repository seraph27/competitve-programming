// Problem: F. Kevin and Math Class
// Contest: Codeforces Global Round 28
// URL: https://codeforces.com/contest/2048/problem/F
// Time Limit: 2000
// Start: Fri May 16 03:18:43 2025
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

const char nl = '\n';
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

int dp[200005][64];

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    vector<int> L(n, -1), R(n, -1), par(n, -1);
    auto cartesian = [&]() -> int{
        vector<int> st;
        for(int i = 0; i < n; i++) {
            int lst = -1;
            while(!st.empty() && b[st.back()] > b[i]) {
                lst = st.back();
                st.pop_back();
            }
            if(!st.empty()) {
                R[st.back()] = i;
                par[i] = st.back();
            }
            if(lst != -1) {
                L[i] = lst;
                par[lst] = i;
            }
            st.push_back(i);
        }
        for(int i = 0; i < n; i++) {
            if(par[i] == -1) return i;
        }
    };
    auto root = cartesian();
    debug(root, L, R, par);
    segtree<int> seg(n);
    for(int i = 0; i < n; i++) {
        seg.update(i, a[i]);
    }

    memset(dp, 0x3f, sizeof(dp));

    for(int i = 0; i < n; i++) {
        int l = L[i]+1, r = (R[i]==-1 ? l : R[i]-1);
        debug(i, l, r);
        int mx = seg.query(l, r);
        dp[i][0] = a[i];
        for(int j = 1; j < 64; j++) {
            assert(mx);
            ckmin(dp[i][j], iceil(dp[i][j-1], mx));
        }
    }
    debug(dp[0][0], dp[0][1], dp[0][2]);
    auto dfs = [&](auto &&s, int u) -> void {
        return;
    };

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

