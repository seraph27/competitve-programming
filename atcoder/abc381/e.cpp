// Problem: E - 11/22 Subsequence
// Contest: AtCoder Beginner Contest 381
// URL: https://atcoder.jp/contests/abc381/tasks/abc381_e
// Time Limit: 3000
// Start: Fri Nov 22 12:30:30 2024
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
    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<int> pref1(n+1), pref2(n+1);
    for(int i = 1; i <= n; i++) {
        pref1[i] = pref1[i-1] + (s[i-1] == '1');
        pref2[i] = pref2[i-1] + (s[i-1] == '2');
    }
    vector<int> slash;
    for(int i = 0; i < n; i++) {
        if(s[i] == '/') slash.push_back(i);
    }

    for(;q--;) {
        int l, r; cin >> l >> r;
        l--, r--;

        auto L = lower_bound(all(slash), l) - slash.begin();
        auto R = upper_bound(all(slash), r) - slash.begin();
        --R;
        int ans = 0;
        while(L <= R) {
            int mid = (L+R)/2; 
            int ones = pref1[slash[mid]+1] - pref1[l];
            int twos = pref2[r+1] - pref2[slash[mid]+1];
            ckmax(ans, 2*min(ones, twos) + 1);
            if(ones <= twos) {
                L = mid+1;
            } else {
                R = mid-1;
            }
        }
        cout << ans << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

