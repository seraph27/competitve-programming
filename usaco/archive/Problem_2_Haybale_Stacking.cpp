#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
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
const int INF = 1001001001;

void seraph() {
    int n, k; cin >> n >> k;
    vector<int> hay(n);
    for(int i=0; i<k; i++){
        int a, b; cin >> a >> b;
        --a, --b;
        hay[a]++, hay[b+1]--;
        debug(hay);
    }
    for(int i=1; i<n; i++){
        hay[i] += hay[i-1];
    }
    debug(hay);
    sort(all(hay));
    cout << hay[n/2] << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("stacking.in","r",stdin); freopen("stacking.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}