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

const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int n, k; cin >> n >> k;
    vector<int> vi(n);
    map<int, vector<int>> num;
    map<int, int> mod;
    for(auto&a: vi) {
        cin >> a;
        mod[a%k]++;
        num[a%k].pb(a);
    }
    int cnt = 0;
    for(auto it = mod.begin(); it!=mod.end(); ++it) {
        if((it->second)&1) cnt++; 
    }
    debug(cnt, mod);
    if(n&1&&cnt>1){
        cout << -1 << nl;
        return;
    } else if(n%2 == 0 &&cnt>0) {
        cout << -1 << nl;
        return;
    }
    ll ans = 0;
    for(auto it = num.begin(); it!=num.end(); it++){
        auto v = it->second;
        sort(all(v));
        if(v.size()&1) {
            ll tot = 0;
            ll tot2 = 1e18;
            vector<int> pref(v.size());
            for(int i = 0; i < v.size(); i++) {
                pref[i] += i-1>=0 ? v[i]-v[i-1] : v[i];
            } 
            for(int i = 2; i < v.size(); i+=2) {
                tot += pref[i];
            }
            ckmin(tot2, tot);
            for(int i = 2; i < v.size(); i+=2) {
                ckmin(tot2, tot-pref[i]+pref[i-1]);
                tot = tot-pref[i]+pref[i-1];
            }
            ans+=tot2/k;
        } else{
            ll tot = 0;
            for(int i = 0; i < v.size(); i+=2) {
                tot+=(v[i+1]-v[i]);
            }
            ans+=tot/k;
        }
    }    
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}

