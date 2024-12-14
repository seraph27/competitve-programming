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
    vector<string> spot(n);
    vector<string> plain(n);
    
    for(int i = 0; i < n; i++){
        cin >> spot[i];
    }
    for(int i = 0; i < n; i++){
        cin >> plain[i];
    }
    
    int ans = 0;

    for(int i = 0; i < m; i++){
        set<char> s, p;
        for(auto &a: spot){
            s.insert(a[i]);
        }
        for(auto &b: plain){
            p.insert(b[i]);
        }
        bool saw = false;
        for(auto it = s.begin(); it != s.end(); ++it){
            if(p.count(*it) > 0){
                saw = true;
                break;
            }
        }
        if(!saw) ans++;
    }

    cout << ans << nl;

}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

