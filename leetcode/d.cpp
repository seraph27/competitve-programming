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

template<class T, class Monoid>
struct segtree {
    int n;
    vector<T> t;
    Monoid op;
    T e;
    
    segtree(int siz, Monoid _op, T _e) : n(siz), op(_op), e(_e) {
        t.assign(2 * n, e);
    }
    
    void update(int p, T val) {
        for(ckmax(t[p += n], val); p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
    }
    
    T query(int l, int r) {
        T res = e;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) res = op(res, t[l++]);
            if(r&1) res = op(res, t[--r]);
        }
        return res;
    }
};

struct MaxMonoid { ll operator()(ll a, ll b) const { return max(a, b); } };

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = sz(nums);
        vector<int> coords = nums;
        sort_unique(coords);
        
        auto f = [&](int x) {
            return lower_bound(all(coords), x) - coords.begin();
        };
        
        int m = sz(coords);
        segtree<ll, MaxMonoid> stL(m, MaxMonoid{}, -4e18);
        segtree<ll, MaxMonoid> stR(m, MaxMonoid{}, -4e18);
        
        vector<ll> L(n, -4e18), R(n, -4e18);
        ll ans = -4e18;

        for (int i = 0; i < n; i++) {
            int id = f(nums[i]);
            int prev = i - k;
            
            if (prev >= 0) {
                int pos = f(nums[prev]);
                if (L[prev] > -4e18) stL.update(pos, L[prev]);
                if (R[prev] > -4e18) stR.update(pos, R[prev]);
            }

            L[i] = R[i] = nums[i];

            ll bR = stR.query(0, id);
            if (bR > -4e18) ckmax(L[i], nums[i] + bR);
            ll bL = stL.query(id + 1, m);
            if (bL > -4e18) ckmax(R[i], nums[i] + bL);
            ckmax(ans, max(L[i], R[i]));
        }
        return ans;
    }
};

void slv() {
    Solution s;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) slv();
}
