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

int n, m, k;
int cores[101], cells[101];
int gs[101][101];

void seraph() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        cin >> gs[i][j];
    }

    for(int i = 1; i <= m; i++){ 
        vector<int> cnt(k+1, 0);
        for(int j = 1; j<=n; j++) if(!cores[j]) cnt[gs[j][i]]++;
        for(int j = 1; j<=n; j++) {
            if(gs[j][i] && !cores[j] && (cnt[gs[j][i]]>1 || cells[gs[j][i]])) {
                cores[j] = i;
                cells[gs[j][i]] = 1;
            }
        }
    }
    for(int i = 1; i <=n; i++) cout<<cores[i]<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) seraph();
}

