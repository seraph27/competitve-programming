// Problem: D1. Red Light, Green Light (Easy version)
// Contest: Codeforces Round 1030 (Div. 2)
// URL: https://codeforces.com/contest/2118/problem/D1
// Time Limit: 4000
// Start: Thu Jun 12 15:23:23 2025
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
    int n, k; cin >> n >> k;
    vector<int> pos(n), d(n);
    for(auto&a : pos) cin >> a;
    for(auto&a : d) cin >> a;

    int q; cin >> q;
    while(q--) {
        int st; cin >> st;
        vector<ar<int, 2>> vis(n);
        bool rev = 0;
        auto id = lower_bound(all(pos), st) - pos.begin();
        if(id >= n) {
            cout << "Yes" << nl;
            continue;
        }
        int walked = pos[id] - st;
        while(true) {
            if(id < 0 || id >= n) {
                cout << "Yes" << nl;
                break;
            }
            if(d[id] % k == walked % k) {
                rev ^= 1;
                if(++vis[id][rev] >= 2) {
                    cout << "No" << nl;
                    break;
                }
            }
            if(rev) {
                if(id-1 >= 0) walked += pos[id] - pos[id-1];
                id--;
            } else {
                if(id+1 < n) walked += pos[id+1] - pos[id];
                id++;
            }
        } 
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

