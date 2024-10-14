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

pair<ll, ll> fact(ll n){
    ll i = 1;
    for(; i*i <= n; i++) {
        if(n%i==0) {
            ll val = i+(n/i); //a+b, a-b so given 3, 5 we know can become 4-1, 4+1 -> 5, 3
            if(val%2==0) {
                return {val/2, (n/i)-val/2};
            }
        }
    }
    return {-1, -1};
}
void test() {
    ll n; cin >> n;
    //(a+b)*(a-b)
    auto [one, two] = fact(n);
    if(one < two)swap(one, two);
    if(one==-1 && two==-1) cout << "impossible" << nl;
    else cout << one << " " <<  two << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) test();
}


