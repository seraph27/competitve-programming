// Problem: E - Everything Is A Nail
// Contest: ICPC practice contest
// URL: https://vjudge.net/contest/664971#problem/E
// Time Limit: 5000
// Start: Fri Oct 18 18:48:28 2024
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
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int dp[2][2][2][3];
    memset(dp, 0, sizeof dp);

    for(int i = 0; i < n; i++) {
        int dp2[2][2][2][3];
        memset(dp2, 0, sizeof dp2);
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) for(int ls = 0; ls < 3; ls++) {
                    if(a[i]==0) {
                        if(ls == 0) {
                            ckmax(dp2[1][k][l][0], dp[j][k][l][ls]+1);
                        } 
                        if(j!=1) {
                            ckmax(dp2[1][k][l][0], dp[j][k][l][ls]+1);
                        }
                    }
                    if(a[i]==1) {
                        if(ls == 1) {
                            ckmax(dp2[j][1][l][1], dp[j][k][l][ls]+1);
                        } 
                        if(k!=1){
                            ckmax(dp2[j][1][l][1], dp[j][k][l][ls]+1);
                        }
                    }
                    if(a[i]==2) {
                        if(ls == 2) {
                            ckmax(dp2[j][k][1][2], dp[j][k][l][ls]+1);
                        } 
                        if(l!=1){
                            ckmax(dp2[j][k][1][2], dp[j][k][l][ls]+1);
                        }
                    }
                    ckmax(dp2[j][k][l][ls], dp[j][k][l][ls]);
                }
            }
        }
        swap(dp, dp2);
    }
    int ans = 0;
    for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) for(int l = 0; l < 2; l++) for(int ls = 0; ls < 3; ls++) {
        ans = max(ans, dp[j][k][l][ls]);
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

