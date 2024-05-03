#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef SERAPH
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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 1001001001;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
void seraph() {
    string s, p; cin >> s >> p;
    string s1, s2; 
    vector<int> s1pos, s2pos;
    for(int i = 1; i < p.size(); i++){
        s1=p.substr(0, i);
        s2=p.substr(i, p.size());
        
        string news1 = s1 + '#' + s;
        string news2 = s2 + '#' + s;
        debug(news1, news2);
        auto test1 = prefix_function(news1);
        auto test2 = prefix_function(news2);
        int pos1 = 0;
        for(int j = 0; j < test1.size(); j++){
            if(test1[j]==s1.length()) {
                pos1 = j-2*s1.length();
                s1pos.push_back(pos1);
            }
        }
        int pos2 = -1;
        for(int j = 0; j < test2.size(); j++){
            if(test2[j]==s2.length()) {
                pos2 = j-2*s2.length();
                s2pos.push_back(pos2);
            }
        }
        if(s1pos.size()>0 && s2pos.size()>0){
            for(int k = 0; k < s1pos.size(); k++){
                for(int j = 0; j < s2pos.size(); j++){
                    if(s1pos[k] + s1.length() <= s2pos[j]){
                        cout << s1pos[k] << " " << s1.length() << " " << s2pos[j] << " " << s2.length() << nl;
                        return;
                    }
                    if(s2pos[j] + s2.length() <= s1pos[k]){
                        cout << s1pos[k] << " " << s1.length() << " " << s2pos[j] << " " << s2.length() << nl;
                        return;
                    }
                }
            }
        }
        s1pos.clear();
        s2pos.clear();
    }
    cout << "IMPOSSIBLE" << nl; 
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}