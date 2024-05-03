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
    int n; cin >> n;
    vector<int> tracks(n);
    for(auto&a: tracks) cin >> a;
    vector<int> pref(n);
    for(int i = 0; i < n; i++){
        pref[i] = (i-1>=0 ? pref[i-1] + tracks[i] : tracks[i]);
    }
    debug(pref);
    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        --a; 
        int l = 0, r = n-1, ans = 0;
        while(l<=r){
            int mid = (l+r)>>1;
            if(pref[mid] - pref[a-1] <= b){
                l = mid + 1, ans = mid;
            } else{
                r = mid - 1;
            }
        }

        int mx = -INF, best;
        for(int i = max(a, ans-2); i < min(n, ans+2); i++){
            int sum = pref[i] - pref[a-1];
            int ss = (b + (b - sum + 1)) * sum / 2;
            if(ckmax(mx, ss)) best = i;
        }
        cout << best+1 << " ";
        
    }
    cout << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}