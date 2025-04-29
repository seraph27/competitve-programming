// Problem: Sum of Four Values
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1642
// Time Limit: 1000
// Start: 2025/04/28 0:26:25
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
    int n, x; cin >> n >> x;
    vector<ar<int, 2>> vi(n);
    for(auto&[a, b]: vi) cin >> a;
    for(int i = 0; i < n; i++) vi[i][1] = i+1;
    if(n<4) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    sort(all(vi));
    int p1 = 0, p4 = n-1;
    for(; p1 < n-3; p1++) {
        for(int p3 = p1+2; p3 < n-1; p3++) {
            for(int p2 = p1+1; p2 < p3; p2++) {
                if(p4 < n-1) p4++;
                while(p4-1 > p3 && vi[p1][0] + vi[p2][0] + vi[p3][0] + vi[p4][0] > x) p4--;
                if(vi[p1][0] + vi[p2][0] + vi[p3][0] + vi[p4][0] == x) {
                    cout << vi[p1][1] << " " << vi[p2][1] << " " << vi[p3][1] << " " << vi[p4][1] << nl;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

