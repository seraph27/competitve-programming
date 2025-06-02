// Problem: Problem 1. Angry Cows
// Contest: USACO 2016 January Contest, Gold
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=597
// Time Limit: 4000
// Start: Sun Jun  1 20:50:13 2025
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
    vector<int> vi(n);
    for(int i = 0; i < n; i++) {
        cin >> vi[i];
        vi[i] *= 2;
    }

    sort(all(vi));

    auto calc = [&](int pos, int idx, int radius, int type) -> bool {
        while(true) {
            if(type == 1) {
                //go right
                if(pos + radius >= vi[n-1]) return true;
                int newidx = idx;
                while(newidx < n && pos + radius >= vi[newidx]) newidx++;
                if(newidx == idx) return false;
                assert(newidx-1 >= 0);
                pos = vi[newidx-1];
                idx = newidx;
                radius-=2;
                if(radius < 0) return false;
            } else {
                if(pos - radius <= vi[0]) return true;
                int newidx = idx;
                while(newidx >= 0 && pos - radius <= vi[newidx]) newidx--;
                if(newidx == idx) return false;
                assert(newidx+1 <= n-1);
                pos = vi[newidx+1];
                idx = newidx;
                radius -= 2;
                if(radius < 0) return false;
            }
        }
    };

    int l = 0, r = 2e9, ans = 0;
    while(l<=r) {
        int mid = (l+r)/2;
        int l2 = 0, r2 = 2e9, ans2 = 0; //where to shoot
        
        while(l2 <= r2) {
            int mid2 = (l2 + r2) / 2;
            int where = lower_bound(all(vi), mid2) - vi.begin();
            if(where == n) where = n - 1;
            if(calc(mid2, where, mid, 2)) {
                l2 = mid2 + 1, ans2 = mid2;
            } else {
                r2 = mid2 - 1;
            }
        }
        
        int where2 = upper_bound(all(vi), ans2) - vi.begin();
        if(calc(ans2, where2, mid, 1)) {
            r = mid - 1, ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << fixed << setprecision(1) << (double)ans/2.0 << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("angry.in","r",stdin); freopen("angry.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

