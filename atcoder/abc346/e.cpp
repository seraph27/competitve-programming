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
    int h, w, m; cin >> h >> w >> m;
    vector<ar<int, 3>> p(m);
    set<ar<int, 2>> s;
    for(int i = 0; i < m; i++) {
        int t, a, x; cin >> t >> a >> x;
        p[i] = {t, a, x};
    }
    reverse(all(p));
    vector<ar<int, 3>> proc;
    for(int i = 0; i < m; i++) {
        auto &[t, a, x] = p[i];
        if(s.find({t, a}) == s.end()) {
            s.insert({t, a});
            proc.pb({t, a, x});
        }
    }
    debug(proc);
    vector<ll> color(2e5+5, 0), row(h+5, 0), col(w+5, 0);
    ll rowcnt = h, colcnt = w;
    for(int i = 0; i < proc.size(); i++) {
        auto &[t, a, x] = proc[i];
        debug(t, a, x);
        if(t == 1) {
            color[x] += colcnt;
            rowcnt--;
        } else {
            color[x] += rowcnt;
            colcnt--;
        }
    }
    color[0] += rowcnt*colcnt;
    
    int cnt = 0;
    for(int i = 0; i < color.size(); i++) {
        if(color[i]) cnt++;
    }
    cout << cnt << nl;
    for(int i = 0; i < color.size(); i++) {
        if(color[i]) cout << i << " " << color[i] << nl; 
    }
    
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

