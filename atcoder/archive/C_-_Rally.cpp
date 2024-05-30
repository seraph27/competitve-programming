#include<bits/stdc++.h>
#include <string> 

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;

    int minans = INT_MAX;
    vector<int> v(n);

    for(auto &a: v){
        cin >> a;
    }

    for(int i = 1; i <=100; ++i){
        int total = 0;
       
        for(auto &a : v){
            total += (a-i) * (a-i);
        }
        if(total < minans){
            //cout << total << "\n";
            minans = total;
        }
    }

    cout << minans << endl;
    
    

} 