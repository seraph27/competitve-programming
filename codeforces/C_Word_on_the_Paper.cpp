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
    vector<string> v;
    for(int i = 0; i < 8; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    string ans = "";

    int index;
    for(auto &a: v){
        for(int i = 0; i < 8; i++){
            if(a[i] != '.'){
                index = i;
            }
        }
    }

    for(auto &a: v){
        if(a[index] != '.'){
            ans += a[index];
        }
    }

    cout << ans << "\n";
    
    



}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) test_case();
}