// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)
// codeforces
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

class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
       if(n <= 4) return {};
        vector<ar<int,2>> pool; pool.reserve(n * (n - 1));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i != j) pool.pb({i, j});
        vector<int> deg(n, 2 * (n - 1));
        vector<vector<int>> vi; vi.reserve(sz(pool));
        ar<int,2> last = {-1, -1};
        auto lim = n * n * n * n; int tries = 0;

        while(sz(pool) && tries++ < lim) {
            int bi = -1, best = -1;
            for(int i = 0; i < sz(pool); i++) {
                auto [a, b] = pool[i];
                if(a == last[0] || a == last[1] || b == last[0] || b == last[1]) continue;
                int sc = deg[a] + deg[b];
                if(ckmax(best, sc)) bi = i;
            }
            if(bi != -1) {
                auto e = pool[bi]; pool[bi] = pool.back(); pool.pop_back();
                vi.pb({e[0], e[1]}); deg[e[0]]--; deg[e[1]]--; last = e;
            } else {
                if(vi.empty()) return {};
                ar<int,2> e = {vi.back()[0], vi.back()[1]}; vi.pop_back();
                deg[e[0]]++; deg[e[1]]++;
                last = vi.empty() ? ar<int,2>{-1, -1} : ar<int,2>{ vi.back()[0], vi.back()[1] };
                pool.pb(e);
            }
        }
        if(sz(pool)) return {};
        return vi;
    }
};

void shiina_mashiro() {
    int n; cin >> n;
    Solution s;
    for(int i = 5; i <= 50; i++) {
        auto g = s.generateSchedule(i);
        assert(sz(g) == i * (i - 1));
    }
    
    debug(s.generateSchedule(n));
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}

