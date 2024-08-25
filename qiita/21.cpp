// Problem: D - 射撃王
// Contest: AtCoder Beginner Contest 023
// URL: https://atcoder.jp/contests/abc023/tasks/abc023_d
// Time Limit: 5000
// Start: 2024/08/22 22:33:33

//minimal template
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

const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n; cin >> n;
    vector<ar<ll, 2>> vi(n);
    for(int i = 0; i < n; i++) {
	ll h, s; cin >> h >> s;
	vi[i] = {h, s};
    }
    ll l = 0, r = 4e18, ans = 0;
    while(l<=r) {
	ll mid = l + (r-l)/2;
	int ok = 1;
	vector<ll> f;
	for(int i = 0; i < n; i++) {
	    if(vi[i][0]>mid) {
		ok = 0;
		break;
	    }
	    f.pb((mid - vi[i][0]) / vi[i][1]);
	}
	sort(all(f));
	for(int i = 0; i < sz(f); i++) {
	    if(f[i] < i) {
		ok = 0;
		break;
	    } 
	}

	if(ok) {
	    r = mid - 1, ans = mid;
	} else{
	    l = mid + 1;
	}
    }

    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

