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

using mint = modint998244353;
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w, 0)), b(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> b[i][j];

    vector<int> p(h),q(w);
    iota(all(p), 0), iota(all(q), 0);
    int ans2 = 1e9;
    do {
        do {
            int bad = 0, ans = 0;
            for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
                if(a[i][j] != b[p[i]][q[j]]) {
                    bad = 1;
                    break;
                }
            }

            if(bad) continue;


            debug(p, q);
            for(int i = 0; i < h; i++) for(int j = 0; j < h; j++) if(i < j && p[i] > p[j]) ans++;
            for(int i = 0; i < w; i++) for(int j = 0; j < w; j++) if(i < j && q[i] > q[j]) ans++;
            debug(ans);
            ckmin(ans2, ans);
        } while(next_permutation(all(q)));
    } while(next_permutation(all(p)));

    cout << ((ans2 == 1e9) ? -1 : ans2) << nl;
    
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

