#include<bits/stdc++.h>
#include <string> 
#include <algorithm> 
#include <typeinfo>

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
    vector<int> v(n);

    for(auto &a : v){
        cin >> a;
    }

    int count = n;
    int curr = v[0]; //index 1
    int ans = 1;
    while(count > 0){
        if(curr == 2){
            cout << ans << "\n";
            return 0;
        }
        curr = v[curr - 1]; 
        ans++;
        count--;
    }

    cout << -1 << "\n";
} 