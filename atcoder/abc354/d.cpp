#include <bits/stdc++.h>
#include <atcoder/modint>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
using namespace atcoder;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef SERAPH
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

using mint = modint998244353;
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    a+=(int)1e9; b+=(int)1e9; c+=(int)1e9; d+=(int)1e9;
    ll dx = c-a, dy = d-b;
    ll area = 0;
    int top[8] = {1, 2, 1, 0, 1, 2, 1, 0}, bot[8] = {2, 1, 0, 1, 2, 1, 0, 1};
    bool chk = 0;
    if(c-a < 3) {
        for(int i = a; i<=c; i++){
            if(i%4 == 0) chk = 1;
        }
    }
    int start = a%4, end = c%4;
    debug(chk);
    ll ta = 0, ba = 0;
    if(!chk && c-a < 3) {
        if(end <= start) end +=4;
        for(int i = start; i < end; i++) {
            ta += top[i];
            ba += bot[i];
        }
        dx = 0;
    }
    debug(start, end);
    debug(ta, ba);

    for(int i = 0; i < 4-start; i++) {
        ta += top[3-i];
        ba += bot[3-i];
    }
    for(int i = 0; i < end; i++) {
        ta += top[i];
        ba += bot[i];
    }
    dx-=(4-start+end);
    ta+=dx; ba+=dx;
    
    debug(ta, ba);
    int start2 = abs(b%2), end2 = abs(d%2);
    if(end2) {
        area += ba;
        dy--;
    }
    if(start2) {
        area += ta;
        dy--;
    }
    area += (ll)dy/2*(ta+ba);
    cout << area << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

