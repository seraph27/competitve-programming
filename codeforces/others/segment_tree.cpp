#include <bits/stdc++.h>
#include <atcoder/segtree>
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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

int op(int a, int b) {return max(a, b);};

int e() {return -1;};

int target;

bool f(int r) {return r < target;};

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    segtree<int, op, e> seg(vi);
    for(;q--;) {
        int type; cin >> type;
        if(type == 1) {
            int x, v; cin >> x >> v;
            seg.set(--x, v);
        } else if(type == 2) {
            int l, r; cin >> l >> r;
            cout << seg.prod(--l, r) << nl;
        } else {
            int x, v; cin >> x >> v;
            target = v;
            cout << seg.max_right<f>(--x) + 1 << nl;
        }
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}
