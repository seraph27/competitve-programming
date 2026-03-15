#pragma GCC optimize("O3,unroll-loops")
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
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

struct State {
    int c[3];
    int v[3];
    int sz;
};

void shiina_mashiro() {
    int m, n; cin >> m >> n;
    vector<string> grid(m);
    for(int i = 0; i < m; i++) cin >> grid[i];

    int q; cin >> q;
    vector<vector<int>> H(26, vector<int>(n, -1e9));
    vector<ar<int, 3>> col_recent(n, {-1, -1, -1});
    vector<int> ans(max(n, m) + 2, 0);

    for(int i = 0; i < m; i++) {
        State prev_state;
        prev_state.sz = 0;

        for(int j = 0; j < n; j++) {
            int c = grid[i][j] - 'A';
            H[c][j] = i;

            int pos = -1;
            for(int k = 0; k < 3; k++) {
                if(col_recent[j][k] == c) pos = k;
            }
            if(pos != -1) {
                for(int k = pos; k > 0; k--) col_recent[j][k] = col_recent[j][k-1];
            } else {
                col_recent[j][2] = col_recent[j][1];
                col_recent[j][1] = col_recent[j][0];
            }
            col_recent[j][0] = c;

            int cand[6];
            int cand_sz = 0;
            
            for(int k = 0; k < prev_state.sz; k++) {
                cand[cand_sz++] = prev_state.c[k];
            }
            
            for(int k = 0; k < 3; k++) {
                int cc = col_recent[j][k];
                if(cc != -1) {
                    bool found = false;
                    for(int x = 0; x < prev_state.sz; x++) {
                        if(prev_state.c[x] == cc) { found = true; break; }
                    }
                    if(!found) cand[cand_sz++] = cc;
                }
            }

            int v3 = (j > 0 && prev_state.sz == 3) ? prev_state.v[2] : 1e9;

            int top_c[3] = {-1, -1, -1};
            int top_v[3] = {(int)1e9, (int)1e9, (int)1e9};

            for(int k = 0; k < cand_sz; k++) {
                int cc = cand[k];
                int u = (H[cc][j] < 0) ? 1e9 : (i - H[cc][j] + 1);
                int p = v3;
                
                if(j > 0) {
                    for(int x = 0; x < prev_state.sz; x++) {
                        if(prev_state.c[x] == cc) { p = prev_state.v[x]; break; }
                    }
                }
                
                int nv = (j == 0) ? u : min(u, p + 1);

                if(nv < top_v[0]) {
                    top_v[2] = top_v[1]; top_c[2] = top_c[1];
                    top_v[1] = top_v[0]; top_c[1] = top_c[0];
                    top_v[0] = nv; top_c[0] = cc;
                } else if(nv < top_v[1]) {
                    top_v[2] = top_v[1]; top_c[2] = top_c[1];
                    top_v[1] = nv; top_c[1] = cc;
                } else if(nv < top_v[2]) {
                    top_v[2] = nv; top_c[2] = cc;
                }
            }

            prev_state.sz = 0;
            for(int k = 0; k < 3; k++) {
                if(top_c[k] != -1) {
                    prev_state.c[prev_state.sz] = top_c[k];
                    prev_state.v[prev_state.sz] = top_v[k];
                    prev_state.sz++;
                }
            }

            int mn1 = (prev_state.sz >= 1) ? prev_state.v[0] : 1e9;
            int mn2 = (prev_state.sz >= 2) ? prev_state.v[1] : 1e9;
            int mn3 = (prev_state.sz >= 3) ? prev_state.v[2] : 1e9;

            int mx = min(i + 1, j + 1);
            int L = (q == 2) ? mn2 : mn1;
            int R = min(((q == 2) ? mn3 : mn2) - 1, mx);

            if(L <= R) {
                ans[L]++;
                ans[R+1]--;
            }
        }
    }

    for(int i = 0; i < sz(ans) - 1; i++) ans[i + 1] += ans[i];
    while(sz(ans) > 1 && !ans.back()) ans.pop_back();
    cout << sz(ans) - 1 << nl;
    for(int i = 1; i < sz(ans); i++) cout << ans[i] << " ";
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) shiina_mashiro();
}
