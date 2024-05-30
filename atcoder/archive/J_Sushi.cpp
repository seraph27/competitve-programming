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
const int INF = 1001001001;
const ll INFLL = 100100100100100100;
const char nl = '\n';

void test_case() {
    int n; cin >> n;
    ar<int, 3> sushi{};
    for(int i = 0; i < n; i++){
        int s; cin >> s;
        sushi[s-1]++;
    }
    vector dp(n+1, vector(n+1, vector(n+1, (double)-1)));
    auto solve = [&](auto&& solve, int a, int b, int c) -> double {
        if(dp[a][b][c]>=0) return dp[a][b][c];
        debug("check");
        if(a==0&&b==0&&c==0) return 0;
        double ans = 0.0;
        if(a) ans += solve(solve, a-1, b, c) * a;
        if(b) ans += solve(solve, a+1, b-1, c) * b;
        if(c) ans += solve(solve, a, b+1, c-1) * c;
        ans += n;
        ans *= 1/(double)(a+b+c);
        return dp[a][b][c] = ans;
    };
    
    auto ss = solve(solve, sushi[0], sushi[1], sushi[2]) ;
    cout << fixed << setprecision(20) << ss << nl;  
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("cardgame.in","r",stdin); freopen("cardgame.out","w",stdout);  //ucsao
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}


