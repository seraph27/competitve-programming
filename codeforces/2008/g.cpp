// Problem: G. Sakurako's Task
// Contest: Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/G
// Time Limit: 2000
// Start: 2024/09/01 22:41:43

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n, k; cin >> n >> k;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    
    int gd = vi[0];
    for(int i = 1; i < n; i++) {
        gd = gcd(gd, vi[i]);
    }
    
    if(sz(vi)==1) {
        if(vi[0] < k) cout<<k<<nl;
        else cout<<k-1<<nl;
        return;
    }


    ll l = 0, r = 1e18, ans = 0;
    while(l<=r) {
        ll mid = l + (r-l)/2;
        
        ll has = mid - min((ll)n, mid/gd+1) + 1;
        if(has >= k) {
            r = mid - 1, ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
