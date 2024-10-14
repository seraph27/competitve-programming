#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;

const char nl = '\n';
const int INF = 0x3f3f3f3f;

void test() {
    string s; cin >> s;
    const int mod = 9302023;
    map<string, int> mp;
    mp["one"] = 3;
    mp["two"] = 3;
    mp["three"] = 5;
    mp["four"] = 4;
    mp["five"] = 4;
    mp["six"] = 3;
    mp["seven"] = 5;
    mp["eight"] = 5;
    mp["nine"] = 4;

    //"twone" *2 "threeight" *2
    int mul = 0;
    int len = sz(s);
    for(int i = 0; i < sz(s); i++) {
        auto ss1 = s.substr(i, 9);
        if(ss1=="threeight") {
            len-=4;
            mul++;
            i+=8;
            continue;
        }
        auto ss2 = s.substr(i, 5);
        if(ss2 == "twone") {
            len-=2;
            mul++;
            i+=4;
            continue;
        }
        for(auto &[k, v] : mp) {
            if(i+v<=sz(s)) {
                auto ss = s.substr(i, v);
                if(ss==k) {
                    len-=v-1;
                    i+=v-1;
                    break;
                }
            }
        }
    }
    int ans = 1;
    for(int i = 0; i < mul; i++) {
        ans*=2;
        if(ans>mod) ans%=mod;
    }
    cout << len << " " << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) test();
}


