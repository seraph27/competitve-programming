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
    vector<int> shell(3);
    for(int i = 0; i < 3; i++){
        shell[i] = i;
    }

    ar<int, 3> cnt = {};
    for(int i = 0; i < n; i++){
        int a, b, g; cin >> a >> b >> g;
        a--, b--, g--;
        swap(shell[a], shell[b]);
        cnt[shell[g]]++;
    }

    cout << max({cnt[0], cnt[1], cnt[2]}) << nl;
    
}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

