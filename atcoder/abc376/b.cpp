// Problem: B - Hands on Ring (Easy)
// Contest: AtCoder Beginner Contest 376（Promotion of AtCoder Career Design DAY）
// URL: https://atcoder.jp/contests/abc376/tasks/abc376_b
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
    int n, q; cin >> n >> q;
    int ans = 0;
    ar<int, 2> pos = {1, 2};
    for(;q--;) {
        char c; cin >> c;
        int x; cin >> x;
        if(c=='R') {
            int R = 0, L = 0;
            for(int i = pos[1]; i%n!=(x%n); i++) {
                R++;
                if(i%n==pos[0]) {
                    R = INF;
                    break;
                }
            }
            for(int i = pos[1]; ((i+n)%n)!=(x%n); i--) {
                debug((i+n)%n);
                L++;
                if((i+n)%n==pos[0]) {
                    L = INF;
                    break;
                }
            }
            debug(L, R);
            if(L==INF) {
                pos[1] = (pos[1]+R)%n;
            } else {
                pos[1] = (pos[1]-L+n)%n;
            }
            ans+=min(L, R);
        } else {
            debug("asd");
            int R = 0, L = 0;
            for(int i = pos[0]; i%n!=(x%n); i++) {
                R++;
                if(i%n==pos[1]) {
                    R = INF;
                    break;
                }
            }
            for(int i = pos[0]; (i+n)%n!=(x%n); i--) {
                L++;
                if((i+n)%n==pos[1]) {
                    L = INF;
                    break;
                }
            }
            debug(L, R);
            debug(R);
            if(L==INF) {
                pos[0] = (pos[0]+R)%n;
            } else {
                pos[0] = (pos[0]-L+n)%n;
            }
            ans+=min(R, L);
        }
        debug(ans);
        debug(pos[0], pos[1]);
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

