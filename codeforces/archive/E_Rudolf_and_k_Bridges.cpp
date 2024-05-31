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

const ll INFLL = 1E18;
const int INF = 1001001001;
const int mod = 1e9+7;
const char nl = '\n';

void test_case() {
    int n, m, k, d; cin >> n >> m >> k >> d;

    vector<ll> cost(n);
    for(int i = 0; i < n; i++){
        vector<int> depth(m);
        for(auto&a: depth){cin >> a; a++;}
        vector<ll> dp(m, INFLL);

        deque<int> mindp;
        dp[0] = 1;
        for(int j = 0; j < m-1; j++){
            //keep track of idx only idx ok 
            while(!mindp.empty() && dp[mindp.back()] > dp[j]) mindp.pop_back();
            mindp.push_back(j);
            while(j - mindp.front() > d) mindp.pop_front();
            dp[j+1] = dp[mindp.front()] + depth[j+1];
        }
        cost[i] = dp[m-1];
    }

    ll ans = INFLL;
    for(int i = 0; i + k <= n; i++){
        ll tot = 0;
        for(int j = i; j < i + k; j++){
            tot += cost[j];  
        }
        ckmin(ans, tot);
    }

    cout << ans << nl;
    

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}
