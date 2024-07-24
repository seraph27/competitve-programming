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
    //1 2 3 4 5 6 7 8 9 
    //11 22 33 44 55 66 77 88 99
    //101 111 121 131... 191
    //202 212 222 .... 
    //9 * 10 each = 90
    //1001 1111 1221... 1991
    //9*10 each 90
    //10001 10101 10201 ...10901
    //11011 11111 11211....
    //19091 19191... 
    //9*10*10 --> 9 + 9 + 90 + 90 + 900 + 900 + 9000...digit determines the row
    ll n; cin >> n;
    if(n==1) {cout<<0<<nl; return;}
    n-=1;
    string ans = "";
    int base = 1;
    for(ll start = 9, flag = 0; ; start*=(flag?10:1), flag^=1) {
        if(n-start>0) n-=start;
        else break;
        base++;
    }
    string ss = to_string(n);
    int mid = (base+1)/2;
    ans = to_string(stoll('1'+string(mid-1, '0'))+n-1);
    for(int i = (base+1)/2; i < base; i++) {
        ans.pb(ans[base-i-1]);   
    }
    cout<<ans<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

