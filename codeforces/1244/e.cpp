// Problem: E. Minimizing Difference
// Contest: Codeforces Round 592 (Div. 2)
// URL: https://codeforces.com/contest/1244/problem/E
// Time Limit: 2000
// Start: Fri May 30 19:05:57 2025
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
template<typename T> bool ckmax(T &a, const T &b) { return a <= b ? a = b, 1 : 0; }
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
    int n, k; cin >> n >> k;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    sort(all(vi));
    vector<int> pref(n+1);
    for(int i = 0; i < n; i++) {
        pref[i+1] += pref[i] + vi[i];
    }
    int l = 0, r = 1e9, ans = 0;
    while(l<=r) {
        int mid = (l+r)/2;
        int need = 0;
        bool ok = false;
        for(int i = 0; i < n; i++) {
            int j = upper_bound(vi.begin() + i, vi.end(), vi[i] + mid) - vi.begin() -1;

            int lc = vi[i] * i - pref[i];
            int rc = (pref[n] - pref[j+1]) - (n - j - 1) * (vi[i] + mid);
            if(lc + rc <= k) {
                ok = true;
                break;
            }
        }
        for(int i = n-1; i>=0; i--) {
            int j = lower_bound(vi.begin(), vi.begin() + i + 1, vi[i] - mid) - vi.begin();
            int lc = (vi[i] - mid) * j - pref[j];
            int rc = (pref[n] - pref[i+1]) - (n - i - 1) * vi[i];
            if(lc + rc <= k) {
                ok = true;
                break;
            }
        }
        if(ok) {
            r = mid - 1, ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << nl;

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

