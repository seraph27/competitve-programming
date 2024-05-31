#include<bits/stdc++.h>
#include <string> 

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int test;
	cin >> test;

    for (int T = 0; T < test; T++) {
        int n, h, m; cin >> n >> h >> m;

        vector<int> sleepTime(n-1);
        int min;

        for(int i = 0; i < n; i++){
            int ans = INT_MAX;
            int hh, mm; cin >> hh >> mm;
            int totH = (hh - h);
            int totM = (mm - m);

            if (totH < 0){
                totH+=24;
            }
            if(totM < 0){
                totM+=60;
                totH--;
            }

            min = totH * 60 + totM;

            if(totH * 60 + totM < ans){
                ans = min;
            }
        }

        cout << to_string(min / 60) + " " + to_string(min % 60) << endl;

        
    }  
} 