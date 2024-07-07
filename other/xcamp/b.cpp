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
const int INF = 0x3f3f3f3f;

void seraph() {
    int n, k; cin >> n >> k;
    vector<ll> beauty(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        beauty[i] = a;
    }
    sort(all(beauty));
    debug(beauty); 

    int median = (k%2 ? k/2 : k/2-1);
    ll front = 0, back = 0;
    ll summ = 0;
    for(int i = 0; i < k; i++){
        summ += (ll)abs((beauty[median] - beauty[i]));
    }  
    debug(summ);
    ll ans = summ;
    ll minidx = 0;
    for(int i = 0; i + k < n; i++){
        summ-=(ll)(beauty[median]-beauty[i]) * (beauty[median]-beauty[i]);
        summ+=(ll)(beauty[k+i] - beauty[median])*(beauty[k+i] - beauty[median]);
        if(ckmin(ans, summ)) minidx = i;
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}