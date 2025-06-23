// Problem: H. Ammar-utiful Array
// Contest: The 2023 Damascus University Collegiate Programming Contest
// URL: https://codeforces.com/gym/104468/problem/H
// Time Limit: 1000
// Start: Thu Jun  5 23:40:44 2025
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
    int n; cin >> n;
    vector<int> values(n), color(n);
    for(auto&a : values) cin >> a;
    for(auto&a : color) {
        cin >> a;
        --a;
    }
    const int MX = 2e5+5;
    vector<vector<int>> by_color(MX);
    for(int i = 0; i < n; i++) {
        by_color[color[i]].pb(values[i]);
    }
    
    vector<vector<int>> by_color_pref(MX);
    for(int i = 0; i < MX; i++) {
        vector<int> pref(sz(by_color[i]) + 1);
        for(int j = 0; j < sz(by_color[i]); j++) {
            pref[j+1] = pref[j] + by_color[i][j];
        }
        by_color_pref[i] = pref;
    }
    
    int tot_add = 0;
    vector<int> minus(MX);
    int q; cin >> q;
    for(;q--;) {
        int type; cin >> type;
        if(type == 1) {
            int col, X; cin >> col >> X;
            --col;
            minus[col] += X;
            tot_add += X;
        } else {
            int col, Y; cin >> col >> Y;
            --col;
            int l = 0, r = sz(by_color_pref[col]) - 1, ans = 0;
            while(l<=r) {
                int mid = (l+r) >> 1;
                if(by_color_pref[col][mid] + (tot_add - minus[col]) * mid <= Y) {
                    l = mid + 1, ans = mid;
                } else {
                    r = mid - 1;
                }
            }
            cout << ans << nl;
        }
    }

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

