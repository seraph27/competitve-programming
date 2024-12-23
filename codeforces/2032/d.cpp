// Problem: D. Genokraken
// Contest: Codeforces Round 983 (Div. 2)
// URL: https://codeforces.com/contest/2032/problem/D
// Time Limit: 2000
// Start: 2024/11/10 12:33:15
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
    int n; cin >> n;

    auto ask = [&](int x, int y) -> int {
        cout << "? " << x <<  " " << y << endl;
        int res; cin >> res;
        return res;
    };

    vector<vector<int>> vi(n+1);
    set<pair<int, int>> st;
    vi[0].pb(1);
    int mxpar = 0;
    int L = -1;
    for(int i = 2; i < n; i++) {
        int res = ask(1, i);
        if(!res) {
            vi[0].pb(i);
            st.insert({i, 0});
            mxpar = 1;
            L = i;
            break;
        } 
    }
    int chain = 1;
    for(int i = 2; i < L; i++) {
        vi[chain].pb(i);
        st.insert({i, chain});
        chain++;
    }
    for(int i = L+1; i < n; i++) {
        debug(i, st, mxpar);
        for(auto [x, y] : st) {
            int res = ask(x, i);
            if(!res) {
                st.erase({x, y});
                st.insert({i, y});
                vi[y].pb(i);
                ckmax(mxpar, x);
                break;
            }
        }
        while(sz(st) && st.begin()->first < mxpar) {
            st.erase(st.begin());
        }
    }
    
    vector<int> par(n+1);
    for(int i = 0; i < sz(vi); i++) {
        if(!sz(vi[i])) break;
        par[vi[i][0]] = 0;
        for(int j = 1; j < sz(vi[i]); j++) {
            par[vi[i][j]] = vi[i][j-1];
        }
    }
    
    cout << "!" << " ";
    for(int i = 1; i < n; i++) {
        cout << par[i] << " ";
    }
    cout << endl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

