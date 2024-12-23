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

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n);
    for(int i = 0; i < n; i++) cin >> vi[i];
    int issort = 1;

    set<int> s;
    int bad = 1, hascorrectidx = 0;
    for(int i = 0; i < n; i++) {
        if(vi[i] != i+1) issort = 0;
        if(vi[i] == i+1) {
            hascorrectidx = 1;
            debug(vi[i], i+1);
            debug(s);
            if(s.size() && *prev(s.end()) < i+1) {
                bad = 0;
            }  
        }
        s.insert(vi[i]);
    }
    if(issort) {
        cout<<0<<nl;
        return;
    }
    if((!bad && hascorrectidx) || vi[0] == 1) {
        cout<<1<<nl;
        return;
    }
    if(vi[0] == n && vi[n-1] == 1) {
        cout<<3<<nl;
        return;
    }
    cout<<2<<nl;
    return;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

