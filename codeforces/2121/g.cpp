// Problem: G. Gangsta
// Contest: Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/contest/2121/problem/G
// Time Limit: 2000
// Start: 2025/06/20 10:30:07
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

//outside is all 0-indexed, inclusive, so [l, r]
//don't add 1 to update;
void shiina_mashiro() {
    int n; cin >> n;
    string s; cin >> s;
    //max(a, b) = a + b + |a - b|

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (i + 1) * (n - i);
    }
    vector<int> bal(n+1, 0);
    for(int i = 0; i < n; i++) {
        bal[i+1] = bal[i] + (s[i] == '1' ? 1 : -1);
    }
    int mn = *min_element(all(bal));
    if(mn < 0) for(int i = 0; i <= n; i++) bal[i] -= mn;
    fenwick<int> fw(n+1);
    fenwick<int> fw2(n+1);
    for(int i = 0; i <= n; i++) {
        fw.update(bal[i], bal[i]);
        fw2.update(bal[i], 1);
        int front = fw.query(0, bal[i]);
        int back = fw.query(bal[i], n);
        ans += bal[i] * fw2.query(0, bal[i]) - front;
        ans += back - bal[i] * fw2.query(bal[i], n);
    }
    cout << ans/2 << nl;
    
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

