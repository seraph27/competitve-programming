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
    int n, m; cin >> n >> m;
    vector<int> vi(100);
    vector<int> vi2(100);

    int ans = 0; 
    int cur = 0; 
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        for(int i = 0; i < a; i++){
            vi[i + cur] = b;
        }
        cur += a;
    }
    cur = 0; 
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        for(int i = 0; i < a; i++){
            vi2[i + cur] = b;
        }
        cur += a;
    }
    for(int i = 0; i < 100; i++){
        if(vi2[i] - vi[i] > ans) ans = vi2[i] - vi[i]; 
    }

    cout << ans << nl;
}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

