// Problem: D. Trash Problem
// Contest: Educational Codeforces Round 95 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1418/problem/D
// Time Limit: 3000
// Start: 2024/09/13 15:42:14

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
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
    // ............... | .................. need to find largest p[i+1] - p[i] for every query
    
    int n, q; cin >> n >> q;
    set<int> s;
    multiset<int> diff;


    auto add = [&](int x) -> void {    // a1 X a2  -> a2-X, X-a1
        auto [it, ok] = s.insert(x);
        assert(ok);
        if(it!=s.begin() && next(it) != s.end()) diff.erase(diff.find(*next(it) - *prev(it)));
        if(it!=s.begin()) diff.insert(*it - *prev(it));
        if(next(it)!=s.end()) diff.insert(*next(it) - *it);
    };

    auto remove = [&](int x) -> void {
        auto it = s.lower_bound(x);
        assert(it != s.end());
        if(next(it)!=s.end()) diff.erase(diff.find(*next(it) - *it)); //a1 remove a2 <- it
        if(it!=s.begin()) diff.erase(diff.find(*it - *prev(it)));
        if(it!=s.begin() && next(it)!=s.end()) diff.insert(*next(it) - *prev(it));
        s.erase(it);
    };
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        add(x);
    }

    auto print = [&]() {
        if(s.size() >= 2) {
            auto mx = *prev(s.end());
            auto mn = *s.begin();
            auto largest_diff = *prev(diff.end());
            cout << mx - mn - largest_diff << nl;
        } else {
            cout << 0 << nl;
        }
    };
    for(int i = -1; i < q; i++) {
        if(i==-1) {
            print();
            continue;
        }
        int type, x; cin >> type >> x;
        if(type==1) {
            add(x);
        } else {
            remove(x);
        }
        print();
    }
}


int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}
