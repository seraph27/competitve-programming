// Problem: Bikes and Barricades
// Contest: unknown_contest
// URL: https://open.kattis.com/problems/bikesandbarricades
// Time Limit: 1000
// Start: Tue Oct  8 21:21:16 2024
// codeforces
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
using point = complex<double>;
#define x() real()
#define y() imag()

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

double cross(point a, point b) {
    return (conj(a) * b).y();
}
point intersection(point a, point b, point p, point q) {
  double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
  return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}
void shiina_mashiro() {
    int n; cin >> n;
    point p = {0, 0}, q = {0, 1};
    vector<ar<point, 2>> vi;
    for(int i = 0; i < n; i++) {
        double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        if((x1>0 && x2>0) || (x1<0 && x2<0)) continue; 
        point one = {x1, y1};
        point two = {x2, y2};
        vi.pb({one, two});
    }
    debug(sz(vi));
    double mn = INF;
    for(int i = 0; i < sz(vi); i++) {
        auto pt = intersection(vi[i][0], vi[i][1], p, q);
        if(pt.y() >= 0) ckmin(mn, pt.y());
    }
    cout << fixed << setprecision(20) << (mn > INF/2 ? -1 : mn) << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}
