// Problem: D. Vasya the Architect
// Contest: School Personal Contest #1 (Winter Computer School 2010/11) - Codeforces Beta Round 38 (ACM-ICPC Rules)
// URL: https://codeforces.com/contest/38/problem/D
// Time Limit: 2000
// Start: Sat Jun  7 01:43:05 2025
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
    vector<ar<int,4>> v(n);
    for (int i = 0; i < n; ++i) {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1,x2);
        if (y1 > y2) swap(y1,y2);
        v[i] = {x1,y1,x2,y2};
    }
    vector<long long> m(n);
    vector<pair<double,double>> c(n);
    for (int i = 0; i < n; ++i) {
        long long s = v[i][2] - v[i][0];
        m[i] = s * s * s;
        c[i] = { (v[i][0] + v[i][2]) * 0.5 , (v[i][1] + v[i][3]) * 0.5 };
    }
    for (int k = 1; k <= n; ++k) {
        double chunk_m = m[k-1];
        double cx = c[k-1].first;
        double cy = c[k-1].second;
        bool ok = true;
        for (int j = k - 2; j >= 0; --j) {
            int xL = max(v[j][0], v[j+1][0]);
            int xR = min(v[j][2], v[j+1][2]);
            int yL = max(v[j][1], v[j+1][1]);
            int yR = min(v[j][3], v[j+1][3]);
            if (cx < xL || cx > xR || cy < yL || cy > yR) {
                ok = false;
                break;
            }
            chunk_m += m[j];
            cx = (cx * (chunk_m - m[j]) + c[j].first * m[j]) / chunk_m;
            cy = (cy * (chunk_m - m[j]) + c[j].second * m[j]) / chunk_m;
        }
        if (!ok) {
            cout << k - 1 << nl;
            return;
        }
    }
    cout << n << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

