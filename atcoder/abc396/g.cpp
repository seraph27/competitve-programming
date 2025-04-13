// Problem: G - Flip Row or Col
// Contest: AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_g
// Time Limit: 2000
// Start: 2025/03/21 23:32:43
// mintemplate
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

void fwht(vector<int>& a, bool inv) {
    int w = __lg(sz(a));
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < 1 << w; j += 1 << (i+1)) {
            for (int k = 0; k < 1 << i; k++) {
                auto l = a[j+k], r = a[(j+k) ^ 1 << i];
                a[j+k] = (l + r) >> inv;
                a[(j+k) ^ 1 << i] = (l - r) >> inv;
            }
        }
    }
}

void shiina_mashiro() {
    int h, w; cin >> h >> w;
    vector<string> vi(h);
    for(auto&a : vi) cin >> a;

    int ans = 1e18;
    vector<int> cnt(1 << w);
    for(auto& a : vi) {
        int mask = 0;
        for(int i = 0; i < w; i++) {
            if(a[i] == '1') mask |= 1 << i;
        }
        cnt[mask]++;
    }
    vector<int> req(1 << w);
    for(int i = 0; i < (1 << w); i++) req[i] = min((int)__builtin_popcount(i), w - __builtin_popcount(i));

    fwht(cnt, 0);
    fwht(req, 0);
    
    for(int i = 0; i < (1 << w); i++) {
        cnt[i] *= req[i];
    }
    fwht(cnt, 1);
    cout << *min_element(all(cnt)) << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

