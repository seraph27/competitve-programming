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

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

const int M1 = 1e9 + 7, M2 = 1e9 + 9;
const int B1 = uniform_int_distribution<int>(137, 1e9 - 1)(rng);
const int B2 = uniform_int_distribution<int>(137, 1e9 - 1)(rng);
vector<int> P1{1}, P2{1};

struct Hash {
    vector<int> h1, h2;
    Hash(const string& s) {
        int n = s.size();
        while (P1.size() <= n) {
            P1.push_back(1LL * P1.back() * B1 % M1);
            P2.push_back(1LL * P2.back() * B2 % M2);
        }
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (1LL * h1[i] * B1 + s[i]) % M1;
            h2[i + 1] = (1LL * h2[i] * B2 + s[i]) % M2;
        }
    }
    pair<int, int> query(int l, int r) {
        int a = (h1[r + 1] - 1LL * h1[l] * P1[r - l + 1]) % M1;
        int b = (h2[r + 1] - 1LL * h2[l] * P2[r - l + 1]) % M2;
        return {a < 0 ? a + M1 : a, b < 0 ? b + M2 : b};
    }
};

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = sz(str1), m = sz(str2), len = n + m - 1;
        //abcdabcdabc....and you have T in the middle of somewhere. then you must gurantee pref[0, T] = suf[m - T, m - 1)
        auto z = z_function(str2);
        vector<int> t_idxs;
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                if(!t_idxs.empty()) {
                    auto lst = t_idxs.back();
                    int d = i - lst;
                    if(d < m && z[d] < m - d) return "";
                } 
            }
            t_idxs.push_back(i);
        }
        
        string ans('?', len);
        int lstfill = -1;
        for(auto idx : t_idxs) {
            for(int j = max(0, lstfill - idx + 1); j < m; j++) {
                ans[idx + j] = str2[j];
            }
            ckmax(lstfill, idx + m - 1);
        }

        Hash target(str2);
        auto [t1, t2] = target.query(0, m - 1); 

        vector<int> h1(len + 1, 0), h2(len + 1, 0);
        for (int i = 0; i < len; i++) {
            for (char c : {'a', 'b'}) {
                if (ans[i] != '?' && ans[i] != c) continue; 
                int nxt1 = (1LL * h1[i] * B1 + c) % M1;
                int nxt2 = (1LL * h2[i] * B2 + c) % M2;

                bool ok = true;
                int start_idx = i - m + 1;
                if (start_idx >= 0 && str1[start_idx] == 'F') {
                    int w1 = (nxt1 - 1LL * h1[start_idx] * P1[m]) % M1;
                    int w2 = (nxt2 - 1LL * h2[start_idx] * P2[m]) % M2;
                    if (w1 < 0) w1 += M1;
                    if (w2 < 0) w2 += M2;

                    if (w1 == t1 && w2 == t2) {
                        ok = false;
                    }
                }

                if (ok) {
                    ans[i] = c;
                    h1[i + 1] = nxt1;
                    h2[i + 1] = nxt2;
                    break; 
                }
            }
        }
        return ans;
    }
};
void slv() {
    Solution s;
    vector<int> vi = {1, 3, 2};
    cout << s.countSubarrays(vi, 4);
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) slv();
}

