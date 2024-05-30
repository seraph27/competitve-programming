#include<bits/stdc++.h>
#include <string> 

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int a, b; cin >> a >> b;

    int outlet = 1;
    int ans = 0;
    while(outlet < b){
        outlet += (a - 1);
        ++ans;
    }

    cout << ans << endl;
    

} 