// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)

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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    map<int, set<int>> has;
    for(int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        mp[a+b]++;
        has[a+b].insert(a);
        has[a+b].insert(b);
    }
    int mn = k;
    for(int i = 0, sum = 3; i < n/2; i++, sum+=2) {
        ckmin(mn, k - (mp[sum] + (sum != (n+1) ? mp[sum + n] : 0)));
        debug(mn, mp, k);
    }
    int get = 0;
    for(int sum = 1; sum < n; sum+=2){
        auto now = has[2*sum+1];
        get += (now.find(sum) != now.end() ? 1 : 0);
    }
    int mn2 = k-get;

    int get2 = 0;
    for(int sum = 2; sum <= n; sum+=2) {
        auto now = has[2*sum+1];
        auto now2 = has[n+1];
        if(sum != n) get2 += (now.find(sum) != now.end() ? 1 : 0);
        else get2 += (now2.find(sum) != now2.end() ? 1 : 0);
    }

    int mn3 = k-get2;
    
    debug(get, get2, mn, mn2, mn3);
    cout << min({mn, mn2, mn3}) << nl;
} 

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

