// Problem: A - Add and Swap
// Contest: AtCoder Regular Contest 187
// URL: https://atcoder.jp/contests/arc187/tasks/arc187_a
// Time Limit: 2000
// Start: Tue Nov 19 19:30:36 2024
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
    int n, k; cin >> n >> k;
    vector<int> vi(n);
    for(auto&x: vi) cin >> x;

    if(n==2) {
        if(vi[1] >= vi[0]) {
            cout << "Yes" << nl;
            cout << 0 << nl;
            return;
        } else if(vi[0]-vi[1] < k) {
            cout << "No" << nl;
            return;
        } else {
            cout << "Yes" << nl;
            cout << 1 << nl;
            cout << 1 << nl;
            return;
        }
    }

    vector<int> ans;
    auto add = [&](int o, vector<int>& v) {
        v[o]+=k;
        v[o+1]+=k;
        ans.pb(o);
        ans.pb(o);
    };
    for(int i = 1; i < n-1; i++) {
        while(vi[i] < vi[i-1]) {
            add(i, vi);
        }
    }

    while(vi[n-1] < vi[n-2] && vi[n-2] - vi[n-1] < k) {
        add(n-3, vi);
    }
    if(vi[n-1] < vi[n-2]) {
        swap(vi[n-1], vi[n-2]);
        vi[n-2]+=k;
        ans.pb(n-2);
    }
    while(vi[n-2] < vi[n-3]) {
        add(n-2, vi);
    }

    assert(sz(ans) < 500000);
    cout << "Yes" << nl;
    cout << sz(ans) << nl;
    for(auto x: ans) cout << x+1 << " ";
    cout << nl;


}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

