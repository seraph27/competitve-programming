#include <bits/stdc++.h>
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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for(auto&x : a) cin >> x;
    vector<ar<int, 3>> op(m);
    for(int i = 0; i < m; i++) {
        int l, r, d; cin >> l >> r >> d;
        op[i] = {l, r, d};
    }

    vector<ll> qpref(m+5, 0);
    for(int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        debug(l, r);
        qpref[l]+=1;
        qpref[r+1]-=1;
    }
    for(int i = 0; i <= m; i++) {
        qpref[i+1]+=qpref[i];
    }
    vector<ll> oppref(n+5);
    for(int i = 0; i < m; i++) {
        auto &[l, r, d] = op[i];
        oppref[l]+=(ll)d*qpref[i+1];
        debug(d, qpref[i+1]);
        oppref[r+1]-=(ll)d*qpref[i+1];
    }
    debug(oppref);
    for(int i = 0; i <= n; i++) {
        oppref[i+1]+=oppref[i];
    }
    debug(oppref);
    for(int i = 1; i <= n; i++) cout<<oppref[i]+a[i-1]<<" ";
    cout<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) seraph();
}

