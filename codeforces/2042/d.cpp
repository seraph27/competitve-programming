// Problem: D. Recommendations
// Contest: Educational Codeforces Round 172 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2042/problem/D
// Time Limit: 2000
// Start: 2024/12/02 6:36:52
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


bool op(ar<int, 3> a, ar<int, 3> b) {
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}
void shiina_mashiro() {
    int n; cin >> n;

    vector<int> dx(n), dy(n);
    vector<ar<int, 3>> vi(n);
    for(int i = 0; i < n; i++) {
        cin >> vi[i][0] >> vi[i][1];
        vi[i][2] = i;
    }

    auto solve = [&](int type) {
        multiset<int> s;
        for(int i = 0; i < n; i++) {
            auto it = s.lower_bound(vi[i][1]);
            if(type==1) dy[vi[i][2]] = it == s.end() ? 0 : *it - vi[i][1];
            else dx[vi[i][2]] = it == s.end() ? 0 : *it - vi[i][1];
            s.insert(vi[i][1]);
            if(i-1>=0 && vi[i][0] == vi[i-1][0] && vi[i][1] == vi[i-1][1]) {
                if(type==1) dy[vi[i-1][2]] = 0;
                else dx[vi[i-1][2]] = 0;
            }
        }
    };

    sort(all(vi), op);
    solve(1);
    for(int i = 0; i < n; i++) swap(vi[i][0], vi[i][1]), vi[i][0] = -vi[i][0], vi[i][1] = -vi[i][1];
    sort(all(vi), op);
    solve(2);
    for(int i = 0; i < n; i++) cout << dx[i] + dy[i] << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

