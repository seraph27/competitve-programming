// Problem: E. Packmen
// Contest: 2017-2018 ACM-ICPC, NEERC, Southern Subregional Contest, qualification stage (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/847/problem/E
// Time Limit: 1000
// Start: Fri Jun  6 16:11:47 2025
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
    string s; cin >> s;

    vector<int> pac;
    set<int> ast1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '*') ast1.insert(i);
        if(s[i] == 'P') pac.pb(i);
    }

    int l = 0, r = n + n, ans = l;
    while(l<=r) {
        int mid = (l+r) >> 1; // how far i can move;
        auto ast = ast1;
        for(auto x : pac) {
            if(ast.empty()) break;
            auto it = ast.begin(); 
            auto pos = *it;
            if(pos > x) {
                 for(auto it2 = it; it2 != ast.end() && *it2 <= x + mid;) {
                    it2 = ast.erase(it2);
                }
            } else {
                auto it2 = ast.lower_bound(x - mid);
                if(it2 != ast.end() && *it2 < x) {
                    int left = max(0LL, mid - 2 * (x - *it2));
                    int right = max(0LL, (mid - (x - *it2)) / 2);
                    debug(left, right, mid);
                    for(; it2 != ast.end() && *it2 <= x + max(left, right);) {
                        it2 = ast.erase(it2);
                    }
                } else if(it2 != ast.end() && *it2 > x) {
                    for(; it2 != ast.end() && *it2 <= x + mid;) {
                        it2 = ast.erase(it2);
                    }
                }
            }
        }

        if(ast.empty()) {
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

