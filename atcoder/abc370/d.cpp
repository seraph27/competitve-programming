// Problem: D - Cross Explosion
// Contest: トヨタ自動車プログラミングコンテスト2024#9（AtCoder Beginner Contest 370）
// URL: https://atcoder.jp/contests/abc370/tasks/abc370_d
// Time Limit: 4000
// Start: 2024/09/24 2:36:47

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
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}

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
    int h, w, q; cin >> h >> w >> q;

    vector<set<int>> row(h+1), col(w+1);
    for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) {
        row[i].insert(j);
        col[j].insert(i);
    }
    debug(row, col);
    auto del = [&](int y, int x) -> void {
        if(row[y].count(x)) row[y].erase(x);
        if(col[x].count(y)) col[x].erase(y);
    };

    for(;q--;) {
        int r, c; cin >> r >> c;
        if(row[r].count(c)) {
            del(r, c);
        } else{
            set<ar<int, 2>> todel;
            auto it = row[r].lower_bound(c);
            if(it != row[r].end()) todel.insert({r, *it});
            if(it != row[r].begin()) todel.insert({r, *prev(it)});
            auto it2 = col[c].lower_bound(r);
            if(it2 != col[c].end()) todel.insert({*it2, c});
            if(it2 != col[c].begin()) todel.insert({*prev(it2), c});
            for(auto &xx : todel) del(xx[0], xx[1]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= h; i++) ans+=row[i].size();
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

