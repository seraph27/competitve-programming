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

template<typename T> struct fenwick {
    int n; vector<T> bit;
    fenwick(int a) : n(a), bit(a+1) {}
    
    T sum(int pos) {
        T s = 0;
        for (; pos; s += bit[pos], pos -= pos&-pos);
        return s;
    }
    T query(int l, int r) {
        return sum(r+1) - sum(l);
    }
    void update(int pos, T x) {
        pos++;
        for (; pos <= n; bit[pos] += x, pos += pos&-pos);
    }
    
    // find k-th smallest (1-indexed k), returns 0-indexed position
    int kth(T k) {
        int pos = 0;
        for (int j = __lg(n); j >= 0; j--) {
            if (pos + (1 << j) <= n && bit[pos + (1 << j)] < k) {
                pos += 1 << j;
                k -= bit[pos];
            }
        }
        return pos;
    }
};

template<typename Add, typename Rem, typename Calc>
struct mo {
    int n, B;
    Add add; Rem rem; Calc calc;
    
    mo(int n_, int q, Add add_, Rem rem_, Calc calc_) 
        : n(n_), B(max(1, (int)(n_ / sqrt(q + 1) + 1))), 
          add(add_), rem(rem_), calc(calc_) {}
    
    template<typename Ans>
    vector<Ans> solve(vector<pair<int,int>>& queries) {
        int q = sz(queries);
        vector<int> ord(q);
        iota(all(ord), 0);
        sort(all(ord), [&](int i, int j) {
            int bi = queries[i].first / B, bj = queries[j].first / B;
            if (bi != bj) return bi < bj;
            return (bi & 1) ? queries[i].second > queries[j].second 
                            : queries[i].second < queries[j].second;
        });
        
        vector<Ans> ans(q);
        int cl = 0, cr = -1;
        for (int i : ord) {
            auto [l, r] = queries[i];
            while (cr < r) add(++cr);
            while (cl > l) add(--cl);
            while (cr > r) rem(cr--);
            while (cl < l) rem(cl++);
            ans[i] = calc();
        }
        return ans;
    }
};

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = sz(nums), q = sz(queries);
        
        vector<int> r(n);
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            r[i] = nums[i] % k;
            v[i] = nums[i] / k;
        }
        
        vector<ll> vv = v;
        sort_unique(vv);
        int V = sz(vv);
        auto id = [&](ll x) { return (int)(lower_bound(all(vv), x) - vv.begin()); };
        
        fenwick<ll> cnt(V), sum(V);
        map<int, int> mp;
        int diff = 0;
        ll tot = 0;
        
        auto add = [&](int i) {
            if (mp[r[i]]++ == 0) diff++;
            int j = id(v[i]);
            cnt.update(j, 1);
            sum.update(j, v[i]);
            tot++;
        };
        auto rem = [&](int i) {
            if (--mp[r[i]] == 0) diff--;
            int j = id(v[i]);
            cnt.update(j, -1);
            sum.update(j, -v[i]);
            tot--;
        };
        auto calc = [&]() -> ll {
            if (diff > 1) return -1;
            if (tot <= 1) return 0;
            int m = cnt.kth((tot + 1) / 2);
            ll med = vv[m];
            ll L = cnt.sum(m + 1), Ls = sum.sum(m + 1);
            ll Rs = sum.sum(V) - Ls;
            return med * L - Ls + Rs - med * (tot - L);
        };
        
        vector<pii> qs(q);
        for (int i = 0; i < q; i++) qs[i] = {queries[i][0], queries[i][1]};
        mo solver(n, q, add, rem, calc);
        return solver.solve<ll>(qs);   
    }
};
void shiina_mashiro() {
    int n; cin >> n;
    Solution s;
    s.
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

