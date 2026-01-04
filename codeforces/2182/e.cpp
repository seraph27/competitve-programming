// Problem: E. New Year's Gifts
// Contest: Educational Codeforces Round 186 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2182/problem/E
// Time Limit: 2000
// Start: Mon Dec 29 23:34:50 2025
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
#define eb emplace_back
#define db double

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

struct Friend {
    int x, y, z, idx, diff;
};
void shiina_mashiro() {
    int n, m, k; cin >> n >> m >> k;
    int ans = 0;

    vector<int> box(m);
    for(int i = 0; i < m; i++) cin >> box[i];

    vector<Friend> vi(n);
    int cost = 0;
    for(int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        vi[i] = {x, y, z, i, z - y};
        cost+=y;
    }
    k -= cost;

    sort(all(box));
    sort(all(vi), [](Friend& f1, Friend& f2) { return f1.x < f2.x; });
    priority_queue<int> pq;

    int idx = 0;
    for(int i = 0; i < m; i++) {
        while(idx < n && vi[idx].x <= box[i]) pq.emplace(vi[idx].diff), idx++;
        if(!pq.empty() ) {
            pq.pop();
            ans++;
        }
    }

    vector<int> left;
    while(!pq.empty()) {
        left.pb(pq.top()), pq.pop();
    }

    for(; idx < n; idx++) left.pb(vi[idx].diff);
    sort(all(left));
    
    for(int i = 0; i < sz(left); i++) {
        if(k >= left[i]) {
            k -= left[i];
            ans++;
        } else break;
    }
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

