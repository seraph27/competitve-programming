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
void test_case() {

    vector<string> target = {
    "###.?????",
    "###.?????",
    "###.?????",
    "....?????",
    "?????????",
    "?????....",
    "?????.###",
    "?????.###",
    "?????.###"
    };

    int n, m; cin >> n >> m;

    vector<string> v(n);

    for(auto &a: v){
        cin >> a;
    }

    for(int i = 0; i < n-8; i++){
        for(int j = 0; j < m-8; j++){
            bool ok = true;
            for(int k = 0; k < 9; k++){
                for(int l = 0; l < 9; l++){
                    ok &= (v[i+k][j+l] == target[k][l] || target[k][l] == '?');
                }
            }

            if(ok){
                cout << i+1 << " " << j+1 << "\n";
            }
        } 
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}