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
    int n, q; cin >> n >> q;
    vector<int> vi(n);

    for(auto &a : vi) cin >> a;

    vector<vector<ll>> vii(400, vector<ll>(n+1, 0));

    for(int i = 0; i < 400; i++){
        for(int j = 0; j < ceil((float)n/(i+1)); j++){
            vii[i][j+1] = vii[i][j] + (ll)(vi[j*(i+1)] * (j+1));
        }
    }

    // for(int i = 0; i < 5; i++){
    //     cout << vii[2][i] << nl;
    // }
     
    for(int i = 0; i < q; i++){
        int s, d, k; cin >> s >> d >> k; 
        ll sum = 0;
        if(d < 400){
            sum += vii[d-1][ceil((float)n/d)];
        } else{
            for(int i = 1; i <= k; i++){
                sum += (ll)vii[0][s + d*(i-1)] * i;
            }
        }
        cout << sum << " ";
    }
    cout << nl;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}