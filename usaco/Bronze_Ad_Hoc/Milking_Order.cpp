// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)
// codeforces
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
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

void shiina_mashiro() {
    int n, m, kk; cin >> n >> m >> kk;
    vector<int> pos(n+1);
    vector<int> order(m);
    for(int i = 0; i < m; i++) {
        cin >> order[i];
    }
    for(int i = 0; i < kk; i++) {
        int c, p; cin >> c >> p;
        pos[p] = c;
    }
    for(int i = 1; i <= n; i++) {
        if(pos[i]) continue;
        vector<int> temp = pos;
        temp[i] = 1;
        int L = 1;
        for(int j = 0; j < m; j++) {
            if(find(all(temp), order[j])!=temp.end()) {
                L = find(all(temp), order[j])-temp.begin();
                continue;
            }
            while(temp[L]) L++;
            assert(L <= n);
            temp[L] = order[j];
        }
        L = 1;
        vector<int> vis(n+1);
        for(int j = 1; j <= n; j++) vis[temp[j]] = 1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j]) {
                while(temp[L]) L++;
                temp[L] = j;
            }
        }
        int ok = 1;
        for(int j = 0; j < m-1; j++) {
            if(find(all(temp), order[j])-temp.begin() > find(all(temp), order[j+1])-temp.begin()) {
                debug(temp, i);
                ok = 0;
                break;
            }
        }
        if(ok) {
            cout << i << nl;
            return;
        }
        debug(temp, i);
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("milkorder.in","r",stdin); freopen("milkorder.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

