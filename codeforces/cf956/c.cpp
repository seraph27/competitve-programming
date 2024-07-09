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

void seraph() {
    int n; cin >> n;
    vector<int> aa(n), bb(n), cc(n);
    for(int i = 0; i < n; i++) {
        cin >> aa[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> bb[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> cc[i];
    }
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    for(int i = 0; i < n; i++) {
        a[i+1] += a[i] + aa[i];
    }
    for(int i = 0; i < n; i++) {
        b[i+1] += b[i] + bb[i];
    }
    for(int i = 0; i < n; i++) {
        c[i+1] += c[i] + cc[i];
    }
    ll tot = accumulate(all(aa), 0LL);
    ll sum = (tot + tot%3)/3;
    auto search = [&](auto left, auto mid, auto right) -> ar<int, 6> {    
        int r = 2;
        ll curr = 0;
        for(int l = 2; l < n; l++) {
            while(curr < sum && r < n) {
                curr+=mid[r]-mid[r-1];
                r++;
            }
            if(mid[r] - mid[l-1] < sum) continue;
            ll calca = left[l-1];
            ll calcc = right[n+1] - right[r];
            ll calca2 = left[n+1]-left[r];
            ll calcc2 = right[l-1];
            debug(calca, calcc, calca2, calcc2);
            if(calca >= sum && calcc >= sum) {
                return {1, l-1, l, r, r+1, n};    
            }
            if(calca2 >= sum && calcc2 >= sum) {
                return {1, l-1, l, r, r+1, n}; 
            }
        }
        return {0, 0, 0, 0, 0, 0};
    };
    auto res = search(a, b, c);
    auto res2 = search(a, c, b);
    auto res3 = search(b, a, c);
    auto res4 = search(b, c, a);
    auto res5 = search(c, a, b);
    auto res6 = search(c, b, a);
    debug(res, res2, res3, res4, res5, res6);
    cout << -1 << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}

