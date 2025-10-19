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

const char nl = '\n';

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> par(n + 1, 0);
    vector<int> st;
    int lst = 0;

    for (int i = 0; i < sz(s); ) {
        auto c = s[i];
        if (c >= '0' && c <= '9') {
            int v = 0;
            while (i < sz(s) && s[i] >= '0' && s[i] <= '9') {
                v = v * 10 + (s[i] - '0');
                ++i;
            }
            int id = (int)v;
            par[id] = st.empty() ? 0 : st.back();
            lst = id;
            st.pb(id);
        } else if (c == '(') {
            ++i;
        } else if (c == ')') {
            st.pop_back();
            ++i;
        } 
    }

    for (int i = 1; i <= n; i++) {
        cout << par[i] << (i == n ? nl : ' ');
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
