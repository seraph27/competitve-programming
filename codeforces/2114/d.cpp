// Problem: D. Come a Little Closer
// Contest: Codeforces Round  1027 (Div. 3)
// URL: https://codeforces.com/contest/2114/problem/D
// Time Limit: 2000
// Start: 2025/05/27 11:20:08
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

void shiina_mashiro() {
    int n; cin >> n;
    vector<pair<int, int>> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }

    if(n==1) {
        cout << 0 << nl;
        return;
    }
    vector<int> ix(n), iy(n);
    iota(all(ix), 0);
    iota(all(iy), 0);
    sort(all(ix), [&](int i, int j) { return pts[i].first < pts[j].first; });
    sort(all(iy), [&](int i, int j) { return pts[i].second < pts[j].second; });

    vector<int> cand;
    auto calc = [&](const vector<int> &v) {
        for(auto k : {0LL, 1LL, n-1, n-2}) {
            cand.pb(v[k]);
        }
    };

    calc(ix);
    calc(iy);
    sort_unique(cand);
    int ans = 1e18;
    
    for(int i : cand) {
        int xmin = (ix[0] == i ? pts[ix[1]].first : pts[ix[0]].first);
        int xmax = (ix[n-1] == i ? pts[ix[n-2]].first : pts[ix[n-1]].first);
        int ymin = (iy[0] == i ? pts[iy[1]].second : pts[iy[0]].second);
        int ymax = (iy[n-1] == i ? pts[iy[n-2]].second : pts[iy[n-1]].second);
        ckmin(ans, (xmax - xmin+1) * (ymax - ymin));
        ckmin(ans, (xmax - xmin) * (ymax - ymin+1));
    }
    debug(cand);
    cout << ans << nl;

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

