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
    int n, k, startb, starts; cin >> n >> k >> startb >> starts;
    vector<int> perm(n+1), arr(n+1);
    for(int i = 1; i <= n; i++) cin >> perm[i];
    for(int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> vis(n+1, 0), vis2(n+1, 0);
    vector<int> b_perm, s_perm;
    for(int i = 0; i < min(n, k); i++){
        if(!vis[startb]){
            vis[startb] = 1;
            b_perm.pb(arr[startb]);
            startb = perm[startb];
        }
        if(!vis2[starts]){
            vis2[starts] = 1;
            s_perm.pb(arr[starts]);
            starts = perm[starts];
            debug(starts);
        }
    }
    int stepsb = 0, steps = 0, mxb = 0, mxs = 0;
    for(int i = 0; i < b_perm.size(); i++){
        if(ckmax(mxb, b_perm[i])) {
            stepsb = i;
        }
    }
    for(int i = 0; i < s_perm.size(); i++){
        if(ckmax(mxs, s_perm[i])) {
            steps = i;
        }
    }
    ll totb = 0, tots = 0;
    if(stepsb <= k){  
        for(int i = 0; i < stepsb; i++){
            totb += b_perm[i];
        }
        totb += (ll)(k-stepsb) * b_perm[stepsb];
    } else{
        for(int i = 0; i < k; i++){
            totb += b_perm[i];
        }
    }
    if(steps <= k){  
        for(int i = 0; i < steps; i++){
            tots += s_perm[i];
        }
        tots += (ll)(k-steps) * s_perm[steps];
    } else{
        for(int i = 0; i < k; i++){
            tots += s_perm[i];
        }
        
    }
    debug(tots, totb, s_perm, b_perm);
    if(totb == tots) cout << "Draw" << nl;
    else if(totb < tots) cout << "Sasha" << nl;
    else cout << "Bodya" << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}