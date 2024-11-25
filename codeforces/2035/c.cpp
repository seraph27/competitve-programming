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
    int n; cin >> n;
    vector<int> pow2;
    for(int i = 0; i < 29; i++) {
        pow2.push_back(1<<i);
    }
    if(n==1) {
        cout << 1 << nl;
        cout << 1 << nl;
    } else if(n==2) {
        cout << 2 << nl;
        cout << 1 << " " << 2 << nl;
    } else if(n==3) {
        cout << 2 << nl;
        cout << 1 << " " << 2 << " " << 3 << nl;
    } else if(n==4) {
        cout << 6 << nl;
        cout << 1 << " " << 2 << " " << 3 << " " << 4 << nl;
    } else {
        if(n&1) {
            cout << n << nl;
            for(int i = 1; i <= n; i++) {
                if(i==1 || i==3 || i==n-1 || i==n) continue;
                cout << i << " ";
            }
            cout << 1 << " " << 3 << " " << n-1 << " " << n << nl;
        } else {
            if(n==6) {
                cout << 7 << nl;
                cout << 1 << " " << 2 << " " << 4 << " " << 6 << " " << 5 << " " << 3 << nl;
                return;
            }
            cout << pow2[31-__builtin_clz(n) + 1] - 1 << nl;
            int ok = 0;
            for(int i = 0; i < sz(pow2); i++) {
                if(pow2[i] == n) {
                    ok = 1;
                    break;
                }
            }
            if(ok) {
                int msk = (1<<(31-__builtin_clz(n))) - 1;
                int flip = ~n & msk;
                debug(flip);
                for(int i = 1; i <= n; i++) {
                    if(i==1 || i==3 || i==flip-1 || i==flip || i==n) continue;
                    cout << i << " ";
                }
                cout << 1 << " " << 3 << " " << flip-1 << " " << flip << " " << n << nl;
            } else {
                int msk = (1<<(31-__builtin_clz(n))) - 1;
                for(int i = 1; i <= n; i++) {
                    if(i==msk || i==msk+1 || i==msk+2) continue;
                    cout << i << " ";
                }
                cout << msk+2 << " " << msk+1 << " " << msk << nl;
            }
        }
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

