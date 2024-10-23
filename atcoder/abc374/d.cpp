// Problem: D - Laser Marking
// Contest: キーエンスプログラミングコンテスト2024（AtCoder Beginner Contest 374）
// URL: https://atcoder.jp/contests/abc374/tasks/abc374_d
// Time Limit: 2000
// Start: Sat Oct 12 22:32:26 2024
// mintemplate
#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
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
const int INF = 0x3f3f3f3f;

using pt = complex<double>;
#define x() real()
#define y() imag()

void shiina_mashiro() {
    int n; cin >> n;
    int s, t; cin >> s >> t;
    vector<pair<pt, pt>> points(n);
    for(int i = 0; i < n; i++) {
        double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        pt pt1(x1, y1), pt2(x2, y2);
        points[i] = {pt1, pt2};
    }

    auto dist = [&](pt x, pt y) -> double {
        auto a = x.x(), b = x.y();
        auto c = y.x(), d = y.y();
        return sqrt((c - a) * (c - a) + (d - b) * (d - b));
    };

    double mn = 1e18;
    
    vector<int> idxs(n);
    iota(all(idxs), 0);
    

    do {
        for(int j = 0; j < (1 << n); j++) {
            double tot = 0;
            pt now = {0, 0};
            for(int i = 0; i < n; i++) {
                auto [fi, se] = points[idxs[i]];
                if((j>>i)&1) swap(fi, se);
                tot += dist(now, fi)/s;
                now = se;
                tot+=dist(fi, se)/t;
            }
            ckmin(mn, tot);
        }
    } while(next_permutation(all(idxs)));
    cout << fixed << setprecision(20) << mn << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

