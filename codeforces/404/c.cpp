// Problem: C. Restore Graph
// Contest: Codeforces Round 237 (Div. 2)
// URL: https://codeforces.com/problemset/problem/404/C
// Time Limit: 1000
// Start: 2025/05/27 1:47:22
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
    int n, k; cin >> n >> k;
    vector<vector<int>> vi(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        vi[x].pb(i);
    }
    if(sz(vi[0]) > 1) {
        cout << -1 << nl;
        return;
    }
    vector<ar<int, 2>> ans;

    for(int i = 1; i < n; i++) {
        int L = 0, cnt = (i==1 ? 0 : 1);
        for(auto x : vi[i-1]) {
            while(L < sz(vi[i]) && cnt < k) {
                ans.pb({x+1, vi[i][L]+1});
                L++;
                cnt++;
            }
            cnt = (i==1 ? 0 : 1);
        }
        if(L < sz(vi[i])) {
            cout << -1 << nl;
            return;
        }
    }
    cout << sz(ans) << nl;
    for(auto &[a, b] : ans) cout << a << " " << b << nl;

} 

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

