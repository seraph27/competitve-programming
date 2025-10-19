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
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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

template<typename T> struct fenwick {
    int n; vector<T> bit;
    fenwick(int a) : n(a), bit(a+1) {}
    T sum(int pos) {
        T s = 0;
        for (; pos; s += bit[pos], pos -= pos&-pos);
        return s;
    }
    T query(int l, int r) {
        return sum(r+1) - sum(l);
    }
    void update(int pos, T x) {
        pos++;
        for (; pos <= n; bit[pos] += x, pos += pos&-pos);
    }
};

const char nl = '\n';
void solve() {
    string s; cin >> s;
    int n = sz(s);
    vector<int> pre(n, -1), nxt(n, n), lst(26, -1), RR(26, n);
    for(int i = 0; i < n; i++) {
        auto c = s[i]-'a';
        pre[i] = lst[c];
        lst[c] = i; 
    }
    for(int i = n - 1; ~i; i--) { 
        auto c = s[i]-'a';
        nxt[i] = RR[c];
        RR[c] = i; 
 }

    vector<vector<int>> add(n+1);
    for(int r = 0; r < n; r++) add[pre[r]+1].pb(r);

    fenwick<int> fw(n+5);
    int ans = 0;
    for(int l = 0; l <= n-2; l++){
        for(auto r: add[l]) fw.update(r, 1);
        auto R = nxt[l]-1;
        ans += fw.query(l+1, R);
    }
    cout << ans <<nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
