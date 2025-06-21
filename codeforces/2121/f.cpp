// Problem: F. Yamakasi
// Contest: Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/contest/2121/problem/F
// Time Limit: 3000
// Start: 2025/06/17 23:54:38
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

void shiina_mashiro() {
    int n, s, x; cin >> n >> s >> x;
    vector<int> vi(n);
    for (int i = 0; i < n; i++) {
        cin >> vi[i];
    }

    vector<vector<int>> split;
    int lst = 0;
    for(int i = 0; i < n; i++) {
        if(vi[i] > x) lst = i+1;
        if(vi[i] == x) {
            vector<int> tmp;
            for(; lst < n && vi[lst] <= x; lst++) {
                tmp.pb(vi[lst]);
            }
            if(!tmp.empty()) {
                split.pb(tmp);
            }
        }
    }
    debug(split);
    auto calc = [&](vector<int> &v) {
        int ans = 0;
        map<int, vector<int>> mp;
        int L = -1, R = -1;
        for(int i = 0; i < sz(v); i++) {
            if(v[i] == x) {
                R = i;
                if(L == -1) L = i;
            }
        }
        debug(L, R);
        int sum = 0;
        mp[0].pb(-1);
        int last = -1;
        for(int i = 0; i < sz(v); i++) {
            if (v[i] == x) last = i;
            if(i < L) {
                sum += v[i];
                mp[sum].pb(i);
                continue;
            }
            sum += v[i];
            mp[sum].pb(i);
            if (mp.contains(sum-s)) {
                auto it = lower_bound(all(mp[sum-s]), last);
                ans += it-mp[sum-s].begin();
            }
            debug(mp, sum-s);
        }
        return ans;
    };
    int res = 0;
    for(auto &v : split) {
        res += calc(v);
    }
    cout << res << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

