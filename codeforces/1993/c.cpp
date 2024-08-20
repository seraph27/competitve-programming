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

const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n, k; cin >> n >> k;
    vector<ll> vi(n);
    for(auto&a: vi) cin >> a;
    set<ll> s;
    for(int i = 0; i < k*2; i++) {
        s.insert(i);
    }
    for(int i = 0; i < n; i++) {
        auto mod = vi[i]%(k*2);
        auto high = (mod + k-1);
        int special = 0;
        if(high >= k*2) {
            special = 1;
            high%=(k*2);
        }
        if(!special) {
            auto it = s.lower_bound(high+1);
            while(it != s.end()) {
                it = s.erase(it);
            }
            auto it2 = s.begin();
            while(it2 != s.end() && *it2 < mod) {
                it2 = s.erase(it2);
            }
        } else{
            auto it = s.lower_bound(high+1);
            while(it != s.end() && *it < mod) {
                it = s.erase(it);
            }
        }
        if(s.size() == 0) {
            cout<<-1<<nl;
            return;
        }
    }
    auto mx = *max_element(all(vi));
    for(ll i = mx; i <= mx+4*k+100; i++) {
        if(s.count((i%(k*2)))){
            cout<<i<<nl;
            return;
        }
    }


}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

