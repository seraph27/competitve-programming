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
    vector<ll> vi(n);
    for(auto&a : vi) cin >> a;
    ll sum = reduce(all(vi));
    map<ll, ll> mp;
    ll mx = 0;
    vector<ll> seconditer(n, 0);
    for(int i = 0; i < n; i++) {
        mp[vi[i]]++;
        if(mp[vi[i]]>=2) {
            ckmax(mx, vi[i]);
        }
        seconditer[i] = mx;
    }
    ll sum2 = reduce(all(seconditer));
    

    debug(seconditer, sum2);
    vector<ll> third(n, 0);
    map<ll, ll> mp2;
    ll mx2 = 0;
    for(int i = 0; i < n; i++) {
        mp2[seconditer[i]]++;
        if(mp2[seconditer[i]]>=2) {
            ckmax(mx2, seconditer[i]);
        }
        third[i] = mx2;
    }
    debug(third);
    ll ans = 0;
    ans+=sum;
    ans+=sum2;
    ll sum3 = reduce(all(third));
    ans+=sum3;
    int first = 0;
    for(int i = 0; i < n; i++) {
        if(third[i]>0) {
            first = i;
            break;
        }
    }
    debug(sum3);
    for(int i = 0; i < n-first-1; i++) {
        sum3-=third[n-i-1];
        ans+=sum3;
    } 
    debug(sum2, sum3);
    cout<<ans<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}

