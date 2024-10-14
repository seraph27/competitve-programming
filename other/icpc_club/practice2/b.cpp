#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const char nl = '\n';
const int INF = 0x3f3f3f3f;

using pt = complex<double>;
#define x() real()
#define y() imag()



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






































void test() {
    int n; cin >> n;
    vector<pt> vi(n);
    for(int i = 0; i < n; i++) {
        double x, y; cin >> x >> y;
        vi[i] = {x, y};
    }
    if(n<=6) {
        cout << "possible" << nl;
        return;
    } 

    auto slope = [&](pt a, pt b) -> double {
        return tan(arg(b - a));
    };
    set<double> s;
    for(int i = 0; i < 1000; i++) {
        auto val1 = rng()%n;
        auto val2 = rng()%n;
        auto val3 = rng()%n;
        while(val2==val1) val2 = rng()%n;    
        while(val3==val2) val3 = =rng()%n;
        s.insert(slope(vi[val1], vi[val2]));
    }
    debug(s.size());
    if(s.size()<=n*(n-3)) {
        cout << "possible" << nl;
    } else {
        cout << "impossible" << nl;
    }
   
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) test();
}


