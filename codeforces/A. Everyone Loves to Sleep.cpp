#include<bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int test;
	cin >> test;

    for (int T = 0; T < test; T++) {
        int n, h, m; cin >> n >> h >> m;

        vector<int> sleepTime(n);

        for(int i = 0; i < n; i++){
            int hh, mm; cin >> hh >> mm;
            int totH = (hh - h);
            int totM = (mm - m);

            if (totH < 0){
                totH + 24;
            }
            if(totM < 0){
                totM + 60;
                totH--;
            }
            sleepTime.push_back(totH * 60 + totM);
        }

        int ans = *min_element(sleepTime.begin(), sleepTime.end());
        cout << ans / 60 + ans % 60;
    }  
} 