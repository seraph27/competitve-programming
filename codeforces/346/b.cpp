// Problem: B. Lucky Common Subsequence
// Contest: Codeforces Round 201 (Div. 1)
// URL: https://codeforces.com/problemset/problem/346/B
// Time Limit: 3000
// Start: Sat Apr 25 15:23:44 2026
// multitest
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
#define eb emplace_back
#define db double

using namespace std;
using vc = vector<int>;
using vvc = vector<vc>;
using vvvc = vector<vvc>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a <= b ? a = b, 1 : 0; }
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
struct State {
    int x, y, z;
};
void shiina_mashiro() {
    string s1, s2, virus; cin >> s1 >> s2 >> virus;
    //dp[i][j][k] := lcs using the first i char in s1, first j char in s2 and matches the last X characters of virus
    int n = sz(s1), m = sz(s2), o = sz(virus);
    vvvc dp(n + 1, vvc(m + 1, vc(o + 1, 0)));
    
    vc pi(o, 0);

    for(int i = 1, j = 0; i < o; i++) {
        while(j > 0 && virus[i] != virus[j]) j = pi[j - 1];
        if(virus[i] == virus[j]) j++;
        pi[i] = j;
    }

    vvc kmp(o + 1, vc(26, 0));

    vector<vector<vector<State>>> from(n+1, vector<vector<State>>(m+1, vector<State>(o, {-1, -1, -1})));

    for(int state = 0; state < o; state++) {
        for(int c = 0; c < 26; c++) {
            if(c + 'A' == virus[state]) {
                kmp[state][c] = state + 1;
            } else {
                kmp[state][c] = (state == 0 ? 0 : kmp[pi[state - 1]][c]);
            }
        }
    }


    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k < o; k++) {
                if(i < n && ckmax(dp[i + 1][j][k], dp[i][j][k])) from[i + 1][j][k] = {i, j, k};
                if(j < m && ckmax(dp[i][j + 1][k], dp[i][j][k])) from[i][j + 1][k] = {i, j, k};
                if(i < n && j < m && s1[i] == s2[j]) {
                    int nk = kmp[k][s1[i] - 'A'];
                    if(nk < o) {
                        if(ckmax(dp[i + 1][j + 1][nk], dp[i][j][k] + 1)) from[i + 1][j + 1][nk] = {i, j, k};
                    }
                }
            }
        }
    }

    int ans = 0;
    State best;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) for(int k = 0; k < o; k++) {
        if(ckmax(ans, dp[i][j][k])) best = {i, j, k};
    }

    string path = "";
    while(best.x != -1) {
        State prev = from[best.x][best.y][best.z];
        if(prev.x != -1 && dp[best.x][best.y][best.z] > dp[prev.x][prev.y][prev.z]) {
            path.pb(s1[best.x - 1]);
        }
        best = prev;
    }
    reverse(all(path));

    if(ans == 0)  cout << 0 << nl;
    else cout << path << nl;



}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}
