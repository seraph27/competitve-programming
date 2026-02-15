#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto &x : v) os << x << " "; return os;}

#ifdef MISAKA
struct _debug {
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
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

void shiina_mashiro() {
    int n; cin >> n;
    vector<ar<int, 3>> east, north;
    for(int i = 0; i < n; i++) {
        char c; cin >> c;
        int x, y; cin >> x >> y;
        if(c == 'E') {
            east.pb({x, y, i});
        } else {
            north.pb({x, y, i});
        }
    }


    vector<bool> used(n);
    vector<int> ans2(n, 4e18);
    auto test_barrier = [&]() {
        vector<ar<int, 2>> ans;
    
        for(int i = 0; i < sz(east); i++) {
            int x = east[i][0], y = east[i][1], idx = east[i][2];
            if(used[idx]) continue;
            int eat = 4e18;
            for(int j = 0; j < sz(north); j++) {
                int nx = north[j][0], ny = north[j][1], idx2 = north[j][2];
                if(used[idx2]) {
                    if(y > (ny + ans2[idx2])) continue;
                }
                if(nx < x || ny > y) continue;
                int dx = nx - x, dy = y - ny;
                if(dy < dx) ckmin(eat, dx);
            }
            ans.pb({eat, idx});
        }

        for(int i = 0; i < sz(north); i++) {
            int x = north[i][0], y = north[i][1], idx = north[i][2];
            if(used[idx]) continue;
            int eat = 4e18;
            for(int j = 0; j < sz(east); j++) {
                int ex = east[j][0], ey = east[j][1], idx2 = east[j][2];
                if(used[idx2]) {
                    if(x > (ex + ans2[idx2])) continue;
                }
                if(ex > x || ey < y) continue;
                int dx = x - ex, dy = ey - y;
                if(dy > dx) ckmin(eat, dy);
            }
            ans.pb({eat, idx});
        }
        return ans;
    };
    for(int i = 0; i < n; i++) {
        auto get = test_barrier();
        if(!sz(get)) break;
        sort(all(get));
        used[get[0][1]] = true;
        ans2[get[0][1]] = get[0][0]; 
    }

    for(auto &a : ans2) {
        debug(a);
        if(a == 4e18) {
            cout << "Infinity" << nl;
        } else {
            cout << a << nl;
        }
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}
