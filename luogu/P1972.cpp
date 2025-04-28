// Problem: P1972 [SDOI2009] HH的项链
// Contest: unknown_contest
// URL: https://www.luogu.com.cn/problem/P1972
// Time Limit: 2000
// Start: 2025/04/23 13:11:35
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

template<typename T> struct fenwick {
    int n; vector<T> bit;
    fenwick(int a) : n(a), bit(a+1) {}
    T sum(int pos) {
        T s = 0;
        for (; pos; s += bit[pos], pos -= pos&-pos);
        return s;
    }
    T query(int l, int r) {
        return sum(r+1) - sum(l);
    }
    void update(int pos, T x) {
        pos++;
        for (; pos <= n; bit[pos] += x, pos += pos&-pos);
    }
};

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n);
    for(auto&a: vi) {
        cin >> a;
        --a;
    }
    int q; cin >> q;
    
    vector<ar<int, 3>> queries(q);
    vector<int> ans(q);
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        --l;--r;
        queries[i] = {r, l, i};
    }
    sort(all(queries));
    fenwick<int> bit(n);
    int mx = *max_element(all(vi));
    int idx = 0;
    vector<int> lst(mx+1, -1);
    for(int i = 0; i < n; i++) {
        if(lst[vi[i]] != -1) {
            bit.update(lst[vi[i]], -1);
        }
        bit.update(i, 1);
        lst[vi[i]] = i;
        while(idx < q && queries[idx][0] == i) {
            auto [r, l, id] = queries[idx];
            ans[id] = bit.query(l, r); 
            idx++;
        }
    }
    for(int i = 0; i < q; i++) {
        cout << ans[i] << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

