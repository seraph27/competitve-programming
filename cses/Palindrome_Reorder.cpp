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
    string s; cin >> s;
    int count[26] {};
    for(int i = 0; i < s.length(); i++){
        count[s[i] - 'A']++;
    }
    int odd = 0;
    for(int i = 0; i < 26; i++){
        if(count[i]%2 == 1) odd++;
    }
    if(odd>1){
        cout << "NO SOLUTION" << nl;
        return;
    }

    string ans = "";
    char save;
    bool oddlen = false;
    for(int i = 0; i < 26; i++){
        if(count[i]%2 == 0){
            ans += string(count[i]/2, ('A' + i));
        } else{
            ans += string(count[i]/2, ('A' + i));
            save = 'A' + i;
            oddlen = true;
        }
    }
    string ss = ans;
    reverse(all(ans));
    if(oddlen){
        ans = ss + save + ans;
    } else{
        ans = ss + ans;
    }
    cout << ans << nl;

    
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

