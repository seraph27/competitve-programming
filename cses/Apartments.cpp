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
    int n, m, k; cin >> n >> m >> k;
    vector<int> v1(n);
    vector<int> v2(m); 

    for(auto &a: v1){
        cin >> a;
    }

    for(auto &a: v2){
        cin >> a;
    }

    sort(all(v1));
    sort(all(v2));

    int ans = 0;
    int i = 0, j = 0;
    while(j < v2.size() && i < v1.size()){
        //cout << i << " and " << j << nl;
        if(abs(v2[j] - v1[i]) <= k){
            ans++;
            i++;
            j++;
        } else if(v2[j] < v1[i]){
            j++;
        } else{
            i++;
        }
    }

    cout << ans << nl;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

