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

const char nl = '\n';

void test_case() {
    int n; cin >> n;
    string s; cin >> s;
    int dp[5007];
    for(int i = 0; i <= n; i++) dp[i] = 1e9;
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int sum = 0; 
        for(int j = i; j < n; j++){
            sum += (s[j] == '+' ? 1 : -1);
            dp[j+1] = min(dp[j+1], dp[i] + abs(sum) * (j-i+1));
        }
    }
    cout << dp[n] << nl;
    
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}

