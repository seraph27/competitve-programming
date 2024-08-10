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
    int l = 1, r = 1000;

    auto f = [&](int m1, int m2) -> int {
        cout << "? " << m1 << " " << m2 << endl;
        int in; cin >> in;
        if(in == m1*m2) {
            return 0;
        } else if(in == m1*m2+m1) {
            return 1;
        } else if(in == (m1+1)*(m2+1)) {
            return 2;
        }
        return -1;
    };
    while(r-l > 1) {
        int m1 = l + (r-l) / 3;
        int m2 = l + (r-l) * 2 / 3;
        auto res = f(m1, m2);
        if(res == 0) {
            l = m2;
        } else if(res == 1) {
            l = m1;
            r = m2;
        } else if(res == 2){
            r = m1;
        }
        debug(l, r);
    }
    cout << "! " << r << nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

