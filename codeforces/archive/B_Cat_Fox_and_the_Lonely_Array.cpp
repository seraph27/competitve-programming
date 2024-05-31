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
    vector<int> vi(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> vi[i];
    }
    
    vector<vector<int>> pref(20, vector<int>(n+1, 0));

    for(int i = 0; i < 20; i++){
        for(int j = 1; j <= n; j++){
            pref[i][j] = pref[i][j-1] + (vi[j] & (1 << i) ? 1 : 0);
        }
    }
    debug(pref);
    int l = 1, r = n, ans = 1; 
    while(l<=r){
        int mid = (l+r) >> 1; 
        bool ok = 1;
        for(int bit = 0; bit < 20; bit++){
            int original = pref[bit][mid];
            for(int i = mid + 1; i < pref[bit].size(); i++){
                if(i >= pref[bit].size()) break;
                if(bool(pref[bit][i] - pref[bit][i-mid]) != bool(original)){
                    ok = 0;
                    break;
                }        
            }
            if(!ok) break;
        }    
        if(!ok){
            l = mid + 1;
        } else{
            r = mid - 1, ans = mid;
        }

    }
    cout << ans << nl;
}

// void seraph() {
//     int n; cin >> n;
//     vector<int> vi(n);
//     int kk = 0;
//     for(auto&a: vi) {
//         cin >> a;
//         kk |= a;
//     }
    
//     int ans = 1;
//     for(int i = 0; i < 20; i++){
//         if((kk & (1 << i)) == 0) continue;      
//         vector<int> idx = {0, n+1};
//         for(int j = 1; j <= n; j++){
//             if(vi[j-1] & (1 << i)){
//                 idx.push_back(j);
//             }
//         }
//         sort(all(idx));
//         debug(idx);
//         for(int j = 1; j < idx.size(); j++){
//             ckmax(ans, idx[j] - idx[j-1]);
//         }
//     }
//     cout << ans << nl;
// }

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}