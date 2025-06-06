// Problem: Nested Ranges Count
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/2169
// Time Limit: 1000
// Start: 2025/04/27 16:50:41
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

struct fenwick {
    int n; vector<int> bit;
    fenwick(int sz) : n(sz), bit(sz+1) {};
    
    int lowbit(int x) {
        return x & -x;
    }
    int sum(int pos) {
        int ans = 0;
        for(;pos; pos-=lowbit(pos)) ans+=bit[pos]; 
        return ans;
    }

    void update(int pos, int x) {
        ++pos;
        for(; pos <= n; bit[pos]+=x, pos+=lowbit(pos));
    }

    int query(int l, int r) {
        return sum(r+1) - sum(l);
    }
};
void shiina_mashiro() {
    int n; cin >> n;
    vector<ar<int, 3>> vi(n);
    vector<int> compress;
    compress.reserve(2*n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        vi[i][0] = a, vi[i][1] = b;
        vi[i][2] = i;
        compress.pb(a);
        compress.pb(b);
    }
    sort_unique(compress);
    auto get = [&](int x) {
        return lower_bound(all(compress), x) - compress.begin();
    };
    for(auto &[a, b, c] : vi) {
        a = get(a);
        b = get(b);
    }
    debug(vi);
    sort(all(vi), [&](auto&a, auto&b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }); 
    int m = sz(compress);
    fenwick fw(m);
    vector<int> contains(n, 0);
    for(int i = 0; i < n; i++) {
        int r = vi[i][1];
        contains[vi[i][2]] = fw.query(r, m-1);
        fw.update(r, 1);
    }
    sort(all(vi), [&](auto&a, auto&b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });
    fenwick fw2(m);
    vector<int> contains2(n, 0);
    for(int i = 0; i < n; i++) {
        int l = vi[i][0], r = vi[i][1];
        contains2[vi[i][2]] = fw2.query(l, r);
        fw2.update(r, 1);
    }
    for(auto &x : contains2) cout << x << " ";
    cout << nl;
    for(auto&x : contains) cout << x << " ";
    cout << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}

