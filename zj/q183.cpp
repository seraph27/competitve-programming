// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)
// mintemplate
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
    if(n==1) {
        cout << 0 << nl;
        cout << 0 << nl;
        return;
    }

    vector<int> vi(n * (n-1) /2);
    for(auto&a: vi) cin >> a;
    sort(all(vi));
    int mx = vi.back();
    vector<int> freq(mx+1);
    for(auto x : vi) freq[x]++;
    auto uniq = vi;
    sort_unique(uniq);

    vector<int> ans(n, -1);
    ans[0] = 0, ans[n-1] = mx;
    freq[mx]--;

   
    auto dfs = [&](auto &&s, int l, int r) -> bool {
        if(l>r) return true;

        int z = -1;
        for(int d = mx; d>=0; d--) if(freq[d]>0) {
            z = d;
            break;
        }
        vector<int> used;
        bool ok = 1;
        for(int j = 0; j < n; j++) {
            if(ans[j] >= 0) {
                int d = abs(z - ans[j]);
                freq[d]--;
                used.pb(d);
                if(freq[d] < 0) {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) {
            ans[r] = z;
            if(s(s, l, r-1)) return true;
            ans[r] = -1;
        }
        for(int d : used) freq[d]++;

        int z2 = mx-z;
        used.clear();
        ok = 1;
        for(int j = 0; j < n; j++) {
            if(ans[j] >= 0) {
                int d = abs(z2 - ans[j]);
                freq[d]--;
                used.pb(d);
                if(freq[d] < 0) {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) {
            ans[l] = z2;
            if(s(s, l+1, r)) return true;
            ans[l] = -1;
        }
        for(int d : used) freq[d]++;
        return false;
    };
    assert(dfs(dfs, 1, n-2));
    cout << 0 << " ";
    int lst = 0;
    for(int i = 1; i < sz(ans)-1; i++) {
        int val = lst + ans[n-i] - ans[n-i-1]; 
        cout << val << " "; 
        lst = val;
    }
    cout << mx << nl;
    for(auto &x : ans) cout << x << " ";
    cout << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}


