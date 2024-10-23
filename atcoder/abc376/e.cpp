// Problem: E - Max × Sum
// Contest: AtCoder Beginner Contest 376（Promotion of AtCoder Career Design DAY）
// URL: https://atcoder.jp/contests/abc376/tasks/abc376_e
// Time Limit: 2000
// Start: 2024/10/20 21:28:26
// mintemplate
#include <bits/stdc++.h>
#define sz(x) (int)x.size()
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
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}

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
    int n, k; cin >> n >> k;
    vector<pii> vi(n);
    for (int i = 0; i < n; i++) {
        cin >> vi[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> vi[i].second;
    }
    sort(all(vi));
    debug(vi);
    ll ans = 4e18;
    multiset<ll> s;
    ll sum = 0;
    for(int i = 0; i < k-1; i++) {
        s.insert(vi[i].second);
        sum += vi[i].second;
    }
    for(int i = k-1; i < n; i++) {
        ckmin(ans, vi[i].first * (vi[i].second + sum));
        if(s.empty() || vi[i].second >= *s.rbegin()) continue;
        else {
            debug(s);
            assert(s.size() == k-1);
            sum -= *s.rbegin();
            s.erase(s.find(*s.rbegin()));
            sum += vi[i].second;
            s.insert(vi[i].second);
        }
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

