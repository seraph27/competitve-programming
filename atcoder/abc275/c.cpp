// Problem: C - Counting Squares
// Contest: AtCoder Beginner Contest 275
// URL: https://atcoder.jp/contests/abc275/tasks/abc275_c
// Time Limit: 2000
// Start: 2024/09/11 11:36:05

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
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

int dist (int x1, int y1, int x2, int y2) {
    int dx = x2-x1;
    int dy = y2-y1;
    return dy*dy+dx*dx;
}
void shiina_mashiro() {
    vector<string> vi(9);
    for(int i = 0; i < 9; i++) cin >> vi[i];
    
    ll ans = 0;
    vector<int> get;
    for(int i = 0; i < 9; i++) for(int j = 0; j < 9; j++) {
        for(int i2 = 0; i2 < 9; i2++) for(int j2 = 0; j2 < 9; j2++) {
            for(int i3 = 0; i3 < 9; i3++) for(int j3 = 0; j3 < 9; j3++) {
                for(int i4 = 0; i4 < 9; i4++) for(int j4 = 0; j4 < 9; j4++) {
                    if(vi[i][j]!='#' || vi[i2][j2]!='#' || vi[i3][j3]!='#' || vi[i4][j4]!='#') continue;
                    int dist1 = dist(i, j, i2, j2);
                    int dist2 = dist(i, j, i4, j4);
                    int dist3 = dist(i2, j2, i3, j3);
                    int dist4 = dist(i3, j3, i4, j4);
                    int dist5 = dist(i, j, i3, j3);
                    int dist6 = dist(i2, j2, i4, j4);
                    get.pb(dist1);
                    get.pb(dist2);
                    get.pb(dist3);
                    get.pb(dist4);
                    get.pb(dist5);
                    get.pb(dist6);
                    sort(all(get));
                    int ok = 1;
                    for(int i = 0; i < 4; i++) if(get[i]!=get[0]) ok = 0;
                    if(ok && dist1 != 0 && dist2 != 0 && dist3 != 0 && dist4 != 0)ans++;
                    get.clear();
                }
            }
        }
    }    
    cout << ans / 24;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

