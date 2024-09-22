// Problem: C - Count ABC Again
// Contest: ユニークビジョンプログラミングコンテスト2024 秋（AtCoder Beginner Contest 372）
// URL: https://atcoder.jp/contests/abc372/tasks/abc372_c
// Time Limit: 2000
// Start: 2024/09/21 21:00:24

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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
    string s; cin >> s;
    int cnt = 0;
    for(int i = 0; i < sz(s)-2; i++) {
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') cnt++;
    }
    for(;q--;) {
        int pos;
        char c;
        cin >> pos >> c;
        --pos;
        int before = 0, after = 0;
        debug(s);
        for(int l = max(0, pos-2); l <= min(n-2, pos); l++) {
            if(s[l]=='A'&&s[l+1]=='B'&&s[l+2]=='C') before++;
        }
        s[pos] = c;
        for(int l = max(0, pos-2); l <= min(n-2, pos); l++) {
            if(s[l]=='A'&&s[l+1]=='B'&&s[l+2]=='C') after++;
        }
        debug(s);
        debug(after, before);
        cnt+=(after-before);
        cout << cnt << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

