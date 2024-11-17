// Problem: D. Penchick and Desert Rabbit
// Contest: Codeforces Round 987 (Div. 2)
// URL: https://codeforces.com/contest/2031/problem/D
// Time Limit: 3000
// Start: Fri Nov 15 06:13:09 2024
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
    vector<int> vi(n);
    for(auto &x:vi) {
        cin >> x;
        --x;
    }
    vector<int> minafter(n+1, 4e18), maxbefore(n);
    int mn = 4e18, mx = -1;
    for(int i = n-1; i >= 0; --i) {
        ckmin(mn, vi[i]);
        minafter[i] = mn;
    }
    for(int i = 0; i < n; ++i) {
        ckmax(mx, vi[i]);
        maxbefore[i] = mx;
    }
    debug(maxbefore, minafter);
    vector<int> ans(n, -1);
    int last = -1;
    for(int i = 0; i < n; i++) {
        if(maxbefore[i] <= minafter[i+1]) {
            debug(i, maxbefore[i], minafter[i+1]);
            debug(last);
            for(int j = last+1; j <= i; j++) {
                ans[j] = maxbefore[i];
            }
            last = i;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i]+1 << " \n"[i==n-1];
    }

}
signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

