// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)
// mintemplate
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
    int n, k; cin >> n >> k;
    if(n==1 && k > 1) {
        cout << "No" << nl;
        return;
    }
    if(k==2) {
        cout << "Yes" << nl;
        for(int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << nl;
        for(int i = n; i >= 1; i--) {
            cout << i << " ";
        }
        cout << nl;
        return;
    }
    if(k%n==0){
        int cnt2 = 0;
        for(int i = n-1; i > 0; i--) {
            cnt2*=i;
            if(cnt2 > k/n) {
                cout << "No" << nl;
                return;
            }
        }
        cout << "Yes" << nl;
        vector<int> vi(n);
        iota(all(vi), 1);
        vector<vector<int>> start;
        int cnt = 0;
        do {
            if(cnt==k/n) break;
            start.pb(vi);
            cnt++;
        } while(next_permutation(all(vi)));
        debug(start);
        for(auto &vv: start) {
            for(int i = 0; i < n; i++) {
                rotate(vv.begin(), vv.begin()+1, vv.end());
                for(int j = 0; j < n; j++) {
                    cout << vv[j] << " ";
                }
                cout << nl;
            }
        }
        return;
    }
    cout << "No" << nl;
    return;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

