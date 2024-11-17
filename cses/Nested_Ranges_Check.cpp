// Problem: Nested Ranges Check
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/2168
// Time Limit: 1000
// Start: Tue Nov 12 23:32:32 2024
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

void shiina_mashiro() {
    int n; cin >> n;
    vector<ar<int, 3>> vi(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        vi[i] = {a, b, i};
    }
    sort(all(vi), [&](ar<int, 3> a, ar<int, 3> b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    vector<int> ans1(n), ans2(n); //contains, is contained by
    int mx = vi[0][1];
    for(int i = 1; i < n; i++) {
        if(vi[i][1] <= mx) {
            ans2[vi[i][2]] = 1;
        }
        ckmax(mx, vi[i][1]);
    }
    sort(all(vi), [&](ar<int, 3> a, ar<int, 3> b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });
    int mn = vi[0][1];
    for(int i = 1; i < n; i++) {
        if(vi[i][1] >= mn) {
            ans1[vi[i][2]] = 1;
        }
        ckmin(mn, vi[i][1]);
    }
    for(auto i : ans1) cout << i << ' ';
    cout << nl;
    for(auto i : ans2) cout << i << ' ';
    cout << nl;

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

