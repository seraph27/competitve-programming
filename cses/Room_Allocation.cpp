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
    set<int> s;
    int cnt = 0;
    vector<ar<int, 3>> vi;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        s.insert(i+1);
        vi.pb({a, 0, i+1});
        vi.pb({b, 1, i+1});

    }
    sort(all(vi));
    vector<int> ans(n+1, 0);
    for(int i = 0; i < vi.size(); i++) { //i put all the types in. if i get a 0, then i know, my previous haven't checked out, so it must
        auto &[x, tp, idx] = vi[i];      //take the next one in the set, otherwise, if i get a 1. i check out and put the idx back. 
        debug(s, x, tp, idx);
        if(tp == 0) {
            ans[idx] = *s.begin();
            s.erase(s.begin());
        } else {
            s.insert(ans[idx]);
        }
    }
    cout<<*max_element(all(ans))<<nl;
    for(int i = 0; i < n; i++) cout<<ans[i+1]<<" ";
    cout<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) seraph();
}

