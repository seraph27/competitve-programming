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
    int n; cin >> n;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    map<pair<int, int>, int> mp1, mp2, mp3;
    map<ar<int, 3>, int> all;
    ll sum = 0;
    ll repeat = 0;
    for(int i = 0; i+3 <= n; i++){
        int x1 = vi[i], x2 = vi[i+1], x3 = vi[i+2];
        sum += mp1[{x1, x2}];
        sum += mp2[{x1, x3}];
        sum += mp3[{x2, x3}];
        sum -= all[{x1, x2, x3}] * 3;
        mp1[{x1, x2}]++;
        mp2[{x1, x3}]++;
        mp3[{x2, x3}]++;
        all[{x1, x2, x3}]++;
    }  
    
    cout << sum << nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}