#include <bits/stdc++.h>
#define ll long long
#define ar array
#define db double
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.f); cerr << ','; __print(x.s); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int mod = 1e9+7;
const char nl = '\n';

int sumdigits(int start, int end, string s){
    int sum = 0;
    if(end-start>s.size()) return 0;
    for(int i = start; i < end; i++){
        sum += s[i]-'0';
    }
    return sum;
}
void test_case() {
    int n; cin >> n; 
    vector<string> vv(n);
    vector<vector<int>> vi(6, vector<int>(46, 0)); 
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vv[i] = s;
    }

    for(auto &a: vv){
        int sum = 0;
        for(auto&c : a) sum += c-'0';
        vi[a.length()][sum]++;
    }
    //first part longer
    ll ans = 0;

    for(auto&a: vv){
        for(int i = a.size()%2; i < a.size()+1; i+=2){
            int len = a.size()+i;           
            int firsthalf = sumdigits(0, len/2, a);
            int secondhalf = sumdigits(len/2, a.size(), a);           
            if(firsthalf-secondhalf>=0){
                ans+=vi[i][firsthalf-secondhalf];
            }
        }
    }

    for(auto&a: vv){
        for(int j = a.size()%2; j < a.size(); j+=2){
            int len = a.size()+j;
            int firsthalf = sumdigits(a.size()-len/2, a.size(), a);
            int secondhalf = sumdigits(0, a.size()-len/2, a);
            if(firsthalf-secondhalf>=0){
                ans+=vi[j][firsthalf-secondhalf];
            }
        }
    }
    cout << ans << nl;


}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
