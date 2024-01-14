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
    string s; cin >> s; 
    s = '0' + s;

    int cut = s.size();

    for(int i = s.size()-1; i>=0; i--){
        if(s[i] >= '5'){
            s[i-1]++;
            cut = i;
        }
    }

    for(int i = (s[0] == '0'); i<sz(s); i++){
        if(i>=cut){
            cout << '0';
        } else{
            cout << s[i];
        }
    }
    cout << "\n";


}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) test_case();
}