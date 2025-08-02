// Problem: E3. Interactive RBS (Hard Version)
// Contest: Codeforces Round 1040 (Div. 2)
// URL: https://codeforces.com/contest/2130/problem/E3
// Time Limit: 2000
// Start: Fri Aug  1 15:23:19 2025
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

string T[12];

void shiina_mashiro() {
    int n; cin >> n;
    

    auto ask = [&](vector<int> &v) -> int {
        cout << "? ";
        cout << sz(v) << " ";
        for(auto&x : v) cout << x + 1 << " ";
        cout << endl;
        int x; cin >> x;
        return x;
    };
    int l = 0, r = n-1, ans = l;
    while(l<=r) {
        int mid = (l+r) >> 1;

        vector<int> q(mid+1);
        iota(all(q), 0);

        if(ask(q) > 0) {
            r = mid - 1, ans = mid;
        } else {
            l = mid + 1;
        }
    }
    int close = ans;

    string S;
    for(int i = 0; i < n; i+=12) {
        vector<int> q;
        for(int j = i; j < min(n, i + 12); j++) {
            auto s = T[j-i];
            for(auto&c : s) {
                if(c == '(') q.pb(j);
                else q.pb(close);
            }
        }
        auto res = ask(q);
        for(int j = i; j < min(n, i + 12); j++) {
            if(res >> (j - i) & 1) S.pb('(');
            else S.pb(')');
        }
    }
    cout << "! " << S << endl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);

    for(int i = 0; i < 12; i++) {
        int rem = 1 << i;
        string s;
        for(int y = 100; y > 0; y--) {
            while(rem - y * (y + 1) / 2 >= 0) {
                rem -= y * (y + 1) / 2;
                for(int j = 0; j < y; j++) {
                    s += "()";
                }
                s += ")";
            }
        }
        T[i] = s;
    }
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

