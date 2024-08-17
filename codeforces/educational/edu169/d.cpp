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
    int n, q; cin >> n >> q;
    vector<string> vi(n);
    for(int i = 0; i < n; i++) {
        cin >> vi[i];
    }
    map<string, int> colorMap = {
        {"BR", 0},
        {"BG", 1},
        {"BY", 2},
        {"GR", 3},
        {"GY", 4},
        {"RY", 5},
    };
    map<string, ar<int, 4>> findMap = {
        {"BR", {1, 2, 3, 5}},
        {"BG", {0, 2, 3, 4}},
        {"BY", {0, 1, 4, 5}},
        {"GR", {0, 1, 4, 5}},
        {"GY", {1, 2, 3, 5}},
        {"RY", {0, 2, 3, 4}},
    };
    ar<vector<int>, 6> dirs;     
    for(int i = 0; i < n; i++) {
        dirs[colorMap[vi[i]]].emplace_back(i); 
    }
    for(auto&vv : dirs) {
        sort(all(vv));
    }

    vector<int> ans;
    for(;q--;) {
        int x, y; cin >> x >> y;
        --x; --y;
        if(x>y) swap(x, y);
        auto sx = vi[x], sy = vi[y];
        int ok = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                if(sx[i] == sy[j]) {
                    ans.pb(abs(x-y));
                    ok = 1;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok) continue;
        int mn = INF; 
        auto now = findMap[vi[x]];
        for(int i = 0; i < 4; i++) {
            auto it = lower_bound(all(dirs[now[i]]), x) - dirs[now[i]].begin();
            for(int j : {it-1, it}) if(j >= 0 && j < (int)dirs[now[i]].size()) {
                int v = dirs[now[i]][j];
                ckmin(mn, (abs(v - x)+ abs(v - y)));
            }
        }
        if(mn == INF) {
            ans.pb(-1);
        } else{
            ans.pb(mn);
        }
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

