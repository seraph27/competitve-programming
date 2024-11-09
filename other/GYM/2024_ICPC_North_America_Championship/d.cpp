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
    int n, m; cin >> n >> m;
    map<int, ar<int, 2>> mp;
    deque<int> vi(n);
    for(int i = 0; i < n; i++) {
        int d; cin >> d;
        vi[i] = d;
    }
    vi.push_front(vi.back());
    vi.push_back(vi[1]);
    debug(vi, sz(vi));
    for(int i = 1; i <= n; i++) {
        mp[vi[i]] = {vi[i-1], vi[i+1]};
    }
    vi.pop_front();
    vi.pop_back();
    debug(mp);
    vector<int> vi2(m);
    for(int i = 0; i < m; i++) {
        cin >> vi2[i];
    }
    debug(vi);
    for(int i = 0; i < m-1; i++) {
        auto nxt = vi2[i+1];
        if(mp[vi2[i]][0] != nxt && mp[vi2[i]][1] != nxt){
            cout << 0 << nl;
            return;
        }
    }
    for(int i = m-1; i>0; i--) {
        auto prev = vi2[i-1];
        if(mp[vi2[i]][0] != prev && mp[vi2[i]][1] != prev) {
            cout<<0<<nl;
            debug("456");
            return;
        }
    }
    cout << 1 << nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

