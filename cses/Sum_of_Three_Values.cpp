// Problem: Sum of Three Values
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1641
// Time Limit: 1000
// Start: Wed Nov 13 22:59:58 2024
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
    int n, x; cin >> n >> x;
    vector<int> vi(n);
    for(auto&o: vi) cin >> o;
    vector<int> idxs(n);
    iota(all(idxs), 0);
    sort(all(idxs), [&](int a, int b){
        return vi[a] < vi[b];
    });
    sort(all(vi));
    if(n < 3){
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    int r = n-1;
    for(int l = 0; l < n-2; l++) {
        for(int m = l+1; m < n-1; m++) {
            if(r < n-1) r++;
            while(r-1 > m && vi[l]+vi[m]+vi[r] > x) r--;
            if(vi[l]+vi[m]+vi[r] == x){
                cout << idxs[l]+1 << ' ' << idxs[m]+1 << ' ' << idxs[r]+1 << nl;
                return;
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
