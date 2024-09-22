// Problem: D - Lunlun Number
// Contest: AtCoder Beginner Contest 161
// URL: https://atcoder.jp/contests/abc161/tasks/abc161_d
// Time Limit: 2000
// Start: 2024/09/17 20:38:19

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
    int k; cin >> k;
    
    vector<ll> vi;
    auto r = [&](auto&&s, string now) -> void {
        if(stoll(now) > 3234566667) return;
        vi.pb(stoll(now));
        int last = now[sz(now)-1]-'0';
        for(int i = max(0, last-1); i <= min(9, last+1); i++) {
            s(s, now + to_string(i));
        }
    };
    for(int i = 1; i <= 9; i++) {
        r(r, to_string(i));
    }
    sort(all(vi));
    cout << vi[k-1] << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

