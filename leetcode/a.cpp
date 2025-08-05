#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ll long long
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

template<typename it, typename bin_op>
struct sparse_table {
    using T = typename remove_reference<decltype(*declval<it>())>::type;
    vector<vector<T>> t; bin_op F;
 
    sparse_table(it first, it last, bin_op op) : t(1), F(op) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < sz(t); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = F(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }
 
    T query(int l, int r) {
        int h = 31 - __builtin_clz(r-l+1);
        return F(t[h][l], t[h][r-(1<<h)+1]);
    }
};

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = sz(nums);
        vector<int> L(n), L2(n), R(n);
        for(int i = 0; i < n; i++) {
            L[i] = (i-1>=0 && nums[i] > nums[i-1] ? L[i-1] + 1 : 1);
            R[i] = (i-1>=0 && nums[i] < nums[i-1] ? R[i-1] + 1 : 1);
        }

        for(int i = n-1; i >= 0; i--) {
            L2[i] = (i+1<n && nums[i] < nums[i+1] ? L2[i+1] + 1 : 1);
        }
        debug(L, L2, R);

        vector<ll> pref(n + 1);
        for(int i = 0; i < n; i++) pref[i + 1] += pref[i] + nums[i];

        ll ans = -4e18;
        auto mn = [&](ll &a, ll &b) {return min(a, b);};
        auto mx = [&](ll &a, ll &b) {return max(a, b);};
        sparse_table st1(all(pref), mn);
        sparse_table st2(all(pref), mx);

        for(int i = 0; i < n; i++) {
            int b = R[i];
            if(b < 2) continue;
            int r1 = i - b + 1;
            int a = L[r1];
            int c = L2[i];

            if(a < 2 || c < 2) continue;

            int l1 = r1 - a + 1;
            int r2 = i + c - 1;
            debug(i + 1, r2 + 1, l1, r1 -1);
            ll MX = st2.query(i + 2, r2 + 1);
            ll MN = st1.query(l1, r1-1);
            debug(MX, MN);
            ckmax(ans, MX - MN);
        }
        return ans;
    }
};

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n);
    for(int i = 0; i < n; i++) cin >> vi[i];
    Solution s;

    cout << s.maxSumTrionic(vi);
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

