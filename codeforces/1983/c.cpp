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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int n; cin >> n;
    vector<ar<ll, 3>> vi(n);
    for(int ii = 0; ii < 3; ii++) for(int i = 0; i < n; i++) cin >> vi[i][ii];
    vector<ar<ll, 3>> pref(n+1);
    for(int ii = 0; ii < 3; ii++) for(int i = 0; i < n; i++) pref[i+1][ii] += pref[i][ii] + vi[i][ii];
    for(int i = 0; i < 3; i++) pref[0][i] = 0;
    ll tot = 0;
    for(int i = 0; i < n; i++) tot+=vi[i][0];

    vector<int> seq = {0, 1, 2};
    vector<pii> ans;
    do {
        for(int l = 1, r = 1; r<=n;r++) {
            ll avg = (tot+2)/3;
            while(l+1<=r && pref[r][seq[1]] - pref[l][seq[1]] >= avg) l++; //[l, r] good
            debug(l, r);
            debug(pref);
            if((pref[l-1][seq[0]] >= avg) && (pref[n][seq[2]] - pref[r][seq[2]] >= avg)) {
                ans.pb({seq[0], 1});
                ans.pb({seq[0], l-1});
                ans.pb({seq[1], l});
                ans.pb({seq[1], r});
                ans.pb({seq[2], r+1});
                ans.pb({seq[2], n});
                sort(all(ans));
                for(auto &[id, val] : ans) cout << val << " ";
                cout << nl;
                return;
            }
        }
    } while(next_permutation(all(seq)));

    cout << -1 << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}

