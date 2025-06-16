// Problem: E - Forbidden Prefix
// Contest: AtCoder Beginner Contest 403
// URL: https://atcoder.jp/contests/abc403/tasks/abc403_e
// Time Limit: 2000
// Start: Wed Jun  4 20:46:02 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
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
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
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

const int MX = 500005;
int q, op[MX], exist[MX], nxt[MX][26], num[MX], tot = 1, ans = 0;
bool vis[MX];
string s[MX];
void shiina_mashiro() {
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> op[i] >> s[i];
        int vtx = 1;
        for(char c : s[i]) {
            if(!nxt[vtx][c-'a']) nxt[vtx][c-'a'] = ++tot;
            vtx = nxt[vtx][c-'a'];
        }
        exist[i] = vtx;
    }
    auto dfs = [&](auto&&ss, int u) -> void {
        vis[u] = 1;
        ans-=num[u];
        num[u] = 0;
        for(int i = 0; i < 26; i++) if(nxt[u][i] && !vis[nxt[u][i]]) ss(ss, nxt[u][i]);
        return;
    };
    for(int i = 0; i < q; i++) {
        if(op[i] == 1) {
            if(!vis[exist[i]]) dfs(dfs, exist[i]);
        } else {
            if(!vis[exist[i]]) {
                num[exist[i]]++;
                ans++;
            }
        }
        cout << ans << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

