#include<bits/stdc++.h>
#include <string> 
#include <algorithm> 
#include <typeinfo>

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, c; cin >> n >> m >> c;

    vector<int> v(m);

    for(auto &a : v){
        cin >> a;
    }

    vector<int> v2(m);
    
    int ans = 0;

    for(int i = 0; i < n; i++){
        int total = 0;
        for(auto &b : v2){
            cin >> b;
        }
        for(int j = 0; j < m; j++){
            total += v[j] * v2[j];
        }
        total+=c;
        if(total > 0){
            ans++;
        }
        
    }
    
    cout << ans << "\n";
} 