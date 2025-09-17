// Problem: L. LLMs
// Contest: The 2025 ICPC South America - Brazil First Phase
// URL: https://codeforces.com/gym/106073/problem/L
// Time Limit: 500
// Start: Wed Sep 17 15:58:40 2025
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

void shiina_mashiro() {
    int n; cin >> n;
    // word -> vector
    map<string, pii> dictionary;
    map<string, int> idx;
    for(int i = 0; i < n; i++) {
        string s; 
        int x, y;
        cin >> s >> x >> y;
        dictionary[s] = {x, y};
        idx[s] = i;
    }
    
    int m; cin >> m;
    vector<string> database(m);
    for(int i = 0; i < m; i++) cin >> database[i];

    int q, kk; cin >> q >> kk;
    for(int o = 0; o < q; o++) {
        int len; cin >> len;
        vector<string> words(len);
        for(int i = 0; i < len; i++) cin >> words[i];
        int currwindow = kk;
        bool done = 0;
        vector<string> candidates;
        while(true) {
            for(int i = 0; i < m - currwindow; i++) {
                bool match = 1;
                int start = len - currwindow;
                for(int j = 0; j < currwindow; j++) {
                    if(database[i + j] != words[start + j]) {
                        match = 0;
                        break;
                    }
                }
                if(!match) continue;
                candidates.pb(database[i + currwindow]);
            }
            if(!sz(candidates)) {
                currwindow--;
                if(currwindow == 0) {
                    for(auto &w : words) cout << w << " ";
                    cout << "*" << nl;
                    done = 1;
                    goto end;
                }
            } else break;
        }
        end:;
        if(done) continue;
        vector<int> similiarity;
        vector<pii> cand_vector(sz(candidates));
        for(int i = 0; i < sz(candidates); i++) {
            if(dictionary.count(candidates[i])) cand_vector[i] = dictionary[candidates[i]];
            else cand_vector[i] = {0, 0};
        }
        for(auto &[k, v] : dictionary) {
            int sum = 0;
            for(auto &[x, y] : cand_vector) sum += v.first * x + v.second * y; 
            similiarity.pb(sum);
        }
        debug(similiarity, dictionary);
        assert(sz(similiarity) == n);
        int mx = -4e18; string word;
        int bestidx = 4e18;
        int pos = 0;
        for(auto &[k, v] : dictionary) {
            if(similiarity[pos] == mx) {
                if(ckmin(bestidx, idx[k])) {
                    word = k;
                    bestidx = idx[k];
                }
            } else if(similiarity[pos] > mx) {
                mx = similiarity[pos];
                word = k;
                bestidx = idx[k];
            }
            pos++;
        }
        for(auto &w : words) cout << w << " ";
        cout << word << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

