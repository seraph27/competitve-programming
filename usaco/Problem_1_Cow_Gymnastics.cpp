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
    int k, n; cin >> k >> n;
    set<pair<int, int>> ans;

    if(n == 1){
        cout << nl;
        return;
    } 

    for(int i = 0; i < k; i++){
        vector<int> ranking(n);
        for(int j = 0; j < n; j++){
            cin >> ranking[j];
        }

        for(int ii = 0; ii < n; ii++){
            for(int jj = ii+1; jj < n; jj++){
                ans.insert({ranking[ii], ranking[jj]});
            }
        }
    }

    for(auto it = ans.begin(); it != ans.end();){
        auto fi = ans.find({(*it).second, (*it).first});
        if(fi != ans.end()){
            it = ans.erase(it);
            ans.erase(fi);
        } else{
            ++it;
        }
    }

    cout << ans.size() << nl;
}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

