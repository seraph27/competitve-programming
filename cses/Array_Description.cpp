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
    int n, m; cin >> n >> m;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;

    vector<vector<ll>> dp(n, vector<ll>(m+1, 0));
    //dp[i][j]:= number of array on the ith integer with 
    if(vi[0]==0) fill(dp[0].begin()+1, dp[0].end(), 1);
    else dp[0][vi[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++){
            if(vi[i]==0){
                dp[i][j] = dp[i-1][j] + (j-1>0 ? dp[i-1][j-1] : 0) + (j+1<=m ? dp[i-1][j+1] : 0);
            } else{
                if(j==vi[i]){
                    dp[i][j] = dp[i-1][j] + (j-1>0 ? dp[i-1][j-1] : 0) + (j+1<=m ? dp[i-1][j+1] : 0);
                } 
            }
            if(dp[i][j] > 1e9) dp[i][j]%=mod;
        }
    }

    debug(dp);
    ll ans = 0;
    for(int i = 0; i <= m; i++){
        ans+=dp[n-1][i];
        if(ans>1e9) ans%=mod;
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("cardgame.in","r",stdin); freopen("cardgame.out","w",stdout);  //ucsao
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
