// Problem: D. Mishkin Energizer
// Contest: Codeforces Round 1014 (Div. 2)
// URL: https://codeforces.com/contest/2092/problem/D
// Time Limit: 2000
// Start: 2025/03/29 23:38:54
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
    string s; cin >> s;
    int L = 0, I = 0, T = 0;
    for(char c : s) {
        if(c == 'L') L++;
        else if(c == 'I') I++;
        else T++;
    }


    int mc = -1;
    int limit = 2*n;
    for(int m = 0; m <= limit; m++) {
        if((n+m)%3!=0) continue;
        int x = (n+m)/3;
        if(x >= L && x >= I && x >= T) {
            mc = m;
            break;
        }
    }
    if(mc == -1) {
        cout << -1 << nl;
        return;
    }
    int mx = (n+mc)/3;
    int needI = mx - I;
    int needL = mx - L;
    int needT = mx - T;
    debug(needI, needL, needT);
    auto need = [&](char c1, char c2) -> char {
        if(c1 == 'I' && c2 == 'L') return 'T';
        if(c1 == 'I' && c2 == 'T') return 'L';
        if(c1 == 'L' && c2 == 'I') return 'T';
        if(c1 == 'L' && c2 == 'T') return 'I';
        if(c1 == 'T' && c2 == 'I') return 'L';
        if(c1 == 'T' && c2 == 'L') return 'I';
        return '?';
    };

    int ops = 0;
    vector<int> ans;
    while(needI > 0 || needL > 0 || needT > 0) {
        bool ok = false;
        int savedidx = -1;
        for(int i = 0; i < sz(s)-1; i++) {
            if(s[i] == s[i+1]) continue;
            auto ch = need(s[i], s[i+1]);
            if(savedidx==-1)savedidx = i;
            if((ch == 'I' && needI > 0) || (ch == 'L' && needL > 0) || (ch == 'T' && needT > 0)) {
                s.insert(s.begin()+i+1, ch);
                ans.pb(i+1);
                ops++;
                if(ch == 'I') needI--;
                if(ch == 'L') needL--;
                if(ch == 'T') needT--;
                ok = true;
                break;
            }

        }
        debug(needI, needL, needT, s, ok, savedidx);
        if(!ok && savedidx != -1) {
            auto ch = need(s[savedidx], s[savedidx+1]);
                s.insert(s.begin()+savedidx+1, ch);
                ans.pb(savedidx+1);
                ops++;
                if(ch=='I') {
                    needL++;
                    needT++;
                }
                if(ch=='L') {
                    needI++;
                    needT++;
                }
                if(ch=='T') {
                    needI++;
                    needL++;
                }
            ok = 1;
        }
        if(!ok) {
            break;
        }
    }
    if (needI > 0 || needL > 0 || needT > 0) {
        cout << -1 << nl;
        return;
    }
    debug(ans);
    assert(ops <= 2*n);
    cout << ops << nl;
    for(int i : ans) cout << i << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

