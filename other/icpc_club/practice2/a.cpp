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
    string xs;
    getline(cin, xs);
    transform(all(xs), xs.begin(), [](unsigned char c) {return tolower(c);});
    string s;
    for(auto &c : xs) {
        if(c < 'A' || c > 'z') continue;
        s.pb(c);
    }
    for(int len = 2; len <= sz(s); len++) {
        for(int st = 0; st + len <= sz(s); st++) {
            string ss = s.substr(st, len);
            auto temp = ss;
            reverse(all(temp));
            if(ss==temp) {
                cout << "Palindrome" << nl;
                return;
            } 
        }
    }
    cout << "Anti-palindrome" << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) test();
}


