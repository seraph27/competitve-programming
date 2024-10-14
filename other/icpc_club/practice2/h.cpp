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
    const int n = 8;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x==9) {
            cout << "F" << nl;
            return;
        }
    }
    cout << "S" << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) test();
}


