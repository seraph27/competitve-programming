// Problem: P1120 小木棍
// Contest: unknown_contest
// URL: https://www.luogu.com.cn/problem/P1120
// Time Limit: 260000
// Start: Mon Aug 25 13:22:35 2025
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
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto &x : v) os << x << " "; return os;}

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

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n);
    for (int i = 0; i < n; i++) cin >> vi[i];
    sort(all(vi), greater<int>());
    int st = vi[0];

    vector<int> vis(n, 0);
    bool ok = false;
    int cnt = 0;

    auto dfs = [&](auto&& s, int target, int now, int rest) -> void {
        if (ok) return;
        if (!rest) {
            if (cnt == n) { ok = 1; return; }
            int i = 0; while (i < n && vis[i]) ++i;
            vis[i] = 1; cnt++;
            s(s, target, i, target - vi[i]);
            if (ok) return;
            vis[i] = 0; cnt--;
            return;
        }
        int start = (rest == target ? 0 : now + 1);
        int prev = -1;
        for (int i = start; i < n; i++) if (!vis[i] && vi[i] <= rest && vi[i] != prev) {
            vis[i] = 1; cnt++;
            s(s, target, i, rest - vi[i]);
            if (ok) return;
            vis[i] = 0; cnt--;
            prev = vi[i];
            if (rest == target) return;
            if (vi[i] == rest) return;
        }
    };

    int sum = accumulate(all(vi), 0LL);
    for (int i = st; i <= sum; i++) {
        if (sum % i) continue;
        fill(all(vis), 0);
        ok = false; cnt = 0;
        dfs(dfs, i, 0, i);
        if (ok) { cout << i << nl; return; }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) shiina_mashiro();
}
