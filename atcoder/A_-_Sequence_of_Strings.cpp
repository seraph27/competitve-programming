#include<bits/stdc++.h>
#include <string> 

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	
    int n;  cin >> n;

    vector<string> v(n);

    for(auto &a : v){
        cin >> a;
    }

    for(int i = 0; i < n; i++){
        cout << v[n-i-1] << endl; 
    }

    return 0;
    

} 