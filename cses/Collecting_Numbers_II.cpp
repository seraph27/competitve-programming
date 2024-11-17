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

void seraph() {
    int n, m; cin >> n >> m;
    vector<int> vi(n+1), nums(n+1); 
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        nums[i] = a;
        vi[a] = i;
    }
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(vi[i] > vi[i+1]) ans++; 
    }
    auto chk = [&](int val) -> int {
        return val-1>0 ? vi[val-1] > vi[val] : 0 + val+1<=n ? vi[val] > vi[val+1] : 0;
    };
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if(nums[a] > nums[b]) { 
            swap(a, b);
        }
        int c = 0;
        c -= chk(nums[a]) + chk(nums[b]) - (nums[a]+1 == nums[b] && a > b);
        debug(a, b, nums[a], nums[b], chk(nums[a]), chk(nums[b]), vi);
        swap(nums[a], nums[b]);
        swap(vi[nums[a]], vi[nums[b]]);
        if(nums[a] > nums[b]) { 
            swap(a, b);
        }
        c += chk(nums[a]) + chk(nums[b]) - (nums[a]+1 == nums[b] && a > b);
        ans+=c;
        cout << ans << nl;
    }

   
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}
