// Problem: F. Kevin and Math Class
// Contest: Codeforces Global Round 28
// URL: https://codeforces.com/contest/2048/problem/F
// Time Limit: 2000
// Start: Fri May 16 03:18:43 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2")
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

int dp[200005][64];

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    vector<int> L(n, -1), R(n, -1), par(n, -1);
    auto cartesian = [&]() -> int{
        vector<int> st;
        for(int i = 0; i < n; i++) {
            int lst = -1;
            while(!st.empty() && b[st.back()] > b[i]) {
                lst = st.back();
                st.pop_back();
            }
            if(!st.empty()) {
                R[st.back()] = i;
                par[i] = st.back();
            }
            if(lst != -1) {
                L[i] = lst;
                par[lst] = i;
            }
            st.push_back(i);
        }
        for(int i = 0; i < n; i++) {
            if(par[i] == -1) return i;
        }
    };
    auto root = cartesian();

    sparse_table st(all(a), [](int x, int y){ return max(x,y); });

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 64; j++) {
            dp[i][j] = 1e18;
        }
    }
    //precalc 
    vector<int> bL(n), bR(n);
    auto dfs1 = [&](auto &&s, int u) -> void {
        bL[u] = bR[u] = u;
        if(~L[u]) {
            s(s, L[u]);
            bL[u] = bL[L[u]];
        }
        if(~R[u]) {
            s(s, R[u]);
            bR[u] = bR[R[u]];
        }
    };
    dfs1(dfs1, root);
    auto dfs2 = [&](auto &&s, int u) -> void {
        if(~L[u]) s(s, L[u]);
        if(~R[u]) s(s, R[u]);
        //for(int i = 0; i < 64; i++) for(int j = 0; j < 64; j++) {
        //    if(i+j >= 64) continue;
        //    int l = L[u] == -1 ? -1e9 : dp[L[u]][i];
        //    int r = R[u] == -1 ? -1e9 : dp[R[u]][j];
        //    ckmin(dp[u][i+j], max({l, r, a[u]}));
        //}
        if (~L[u] && ~R[u]) {
            ar<int, 64> comb;
            int i = 0;
            for(int k = 0; k < 64; k++) {
                while(i+1 <= k) {
                    int curr = max({dp[L[u]][i], dp[R[u]][k-i], a[u]});
                    int nxt = max({dp[L[u]][i+1], dp[R[u]][k-i-1], a[u]});
                    if(nxt <= curr) {
                        i++;
                    } else {
                        break;
                    }
                }
                comb[k] = max({dp[L[u]][i], dp[R[u]][k-i], a[u]});
            }
            for(int k = 0; k < 64; k++) {
                ckmin(dp[u][k], comb[k]);
            } 
        } else if (L[u] != -1) {
            for(int i = 0; i < 64; i++) {
                ckmin(dp[u][i], max(dp[L[u]][i], a[u]));
            }
        } else if (R[u] != -1) {
            for(int i = 0; i < 64; i++) {
                ckmin(dp[u][i], max(dp[R[u]][i], a[u]));
            }
        }
        int ll = bL[u], rr = bR[u];
        int mx = st.query(ll, rr);
        dp[u][0] = mx;
        for(int j = 1; j < 64; j++) {
            int m = (dp[u][j-1] + b[u] - 1) / b[u];
            ckmin(dp[u][j], m);
        }
    };

    dfs2(dfs2, root);

    for(int i = 0; i < 64; i++) {
        if(dp[root][i] == 1) {
            cout << i << nl;
            return;
        }
    }
    return;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

