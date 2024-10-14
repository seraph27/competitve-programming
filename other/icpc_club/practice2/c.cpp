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
    int n, k; cin >> n >> k;
    priority_queue<ll> pq;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }


    while(pq.size() >= k && pq.size() >= 2) {
        vector<ll> get;
        for(int i = 0; i < k; i++) {
            auto tp1 = pq.top(); pq.pop();
            get.emplace_back(tp1);
        }
        auto last = get[sz(get)-1];
        for(auto&x : get){
            if(x-((last+1)/2)!=0) pq.push(x-((last+1)/2));
        }
    }
    
    vector<ll> vi;
    while(pq.size()) {
        auto tp = pq.top(); pq.pop();
        vi.emplace_back(tp);
    }
    while(vi.size() < k) vi.pb(0);
    auto mx = *max_element(all(vi));
    
    ll ans = 0;
    for(auto &x : vi) {
        ans += mx - x;
    }
    cout << ans << nl;
    
    //5 2 7 3 2 k = 3
    //0 2 4 2 2 
    //2 2
    //5 7 7 -> 2
    //5 4 4
    //4 3 4 -> 4 4 3
    //3 3 3 
    //2 2 3
    //3 2 2 
    //2 1 2
    //2 2 1
    //1 1 1 
    //0 0 1
    //0 0 0
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) test();
}


