// Problem: E. Arithmetics Competition
// Contest: Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/E
// Time Limit: 3000
// Start: Fri Aug 22 06:14:57 2025
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
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for(auto&x : a) cin >> x;
    for(auto&x : b) cin >> x;
    sort(all(a), greater<int>());
    sort(all(b), greater<int>());

    vector<int> prefa(n + 1), prefb(m + 1);
    for(int i = 0; i < n; i++) prefa[i + 1] += prefa[i] + a[i];
    for(int j = 0; j < m; j++) prefb[j + 1] += prefb[j] + b[j];

    auto f = [&](int x, int z) -> int {
        return prefa[x] + prefb[z - x];
    };  
    for(int i = 0; i < q; i++) {
        int x, y, z; cin >> x >> y >> z;
    
        int L = max(0LL, z - y), R = min(x, z);
        while(L<R) {
            int mid = (L+R) >> 1;
            if(f(mid, z) >= f(mid + 1, z)) {
                R = mid;
            } else {
                L = mid + 1;
            }
        }
        cout << f(L, z) << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

