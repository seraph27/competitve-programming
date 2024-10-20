#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
void solve(){
    int n, h; cin >> n >> h;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(h >= x) ans++;
    }
    cout << ans << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while(t--) solve();
}
