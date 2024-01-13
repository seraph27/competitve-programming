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
    ll n; cin >> n;
    ll tot = ((1+n)*n/2);
    cout << (tot%2 == 1 ? "NO" : "YES") << nl;

    if(tot%2 == 1) return;

    int number = 0; 
    string s1 = "";
    string s2 = "";

    ll cur = tot/2;
    for(int i = n; i > 0; i--){
        if(cur-i >= 0){
            s1+=(to_string(i) + " ");
            number++;
            cur-=i;
        } else{
            s2+=(to_string(i) + " ");
        }
        
    }

    cout << number << nl << s1 << nl;
    cout << n - number << nl << s2 << nl;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

