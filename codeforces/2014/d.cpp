// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)

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

const int INF = 0x3f3f3f3f;
const char nl = '\n';
void shiina_mashiro() {
    ll n, d, k; cin >> n >> d >> k;
    vector<ll> imos(n+5, 0);
    for(;k--;) {
        ll l, r; cin >> l >> r;
        --l;--r;
        ll front = max(l-d+1, 0LL), end = min(r, n-d+1);
        if(front > end) continue;
        imos[front]++;
        imos[end+1]--;
    }
    for(int i = 0; i <= n; i++) {
        imos[i+1]+=imos[i];
    }
    debug(imos);
    ll mn = 4e18, mx = -1;
    ll idxmn = -1, idxmx = -1;
    for(int i = 0; i+d < n+1; i++) {
        debug(i);
        if(ckmax(mx, imos[i])) idxmx = i;
        if(ckmin(mn, imos[i])) idxmn = i;
    }
    cout << idxmx+1 << " " << idxmn+1 << nl;
   

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}


