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

void test_case() {
    int n; cin >> n;
    vector<string> vi(n);
    for(auto&a: vi) cin >> a;
    int ans = 0;

    int minremove = INT_MAX;
    int minelement = -1;
    bool zeromaj = false;
    bool onemaj = false;
    bool mix = false;
    ar<int, n+5> dp;
    int one = count(all(vi[0]), '1'); //one
    int zero = vi[0].length()-one;
    dp[0] = min(one, zero);
    for(int i = 1; i < n; i++){
        one = count(all(vi[i]), '1'); //one
        zero = vi[i].length()-one;
        if(one>zero) onemaj = true;
        if(one<zero) zeromaj = true;
        if(one>0 && zero>0) mix = true;
        dp[i+1] = (!dp[i])
    }
    if(!mix){
        cout << 0 << nl;
        return;
    }
    debug(ans);
    debug(onemaj, zeromaj);
    bool easy = ((zeromaj&&onemaj)||(!zeromaj&&!onemaj));
    if(!easy){
        cout << dp[i] << nl;
        return;
    }
    debug(easy);
    debug(minremove, minelement);

    cout << ans << nl;
    

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
