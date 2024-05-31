#include<bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int test;
	cin >> test;

	for (int T = 0; T < test; T++) {
		int a, b;
		cin >> a >> b;
		vector<vector<int>> adj(a+1);
		vector<int> t(a+1);
		for (int i = 1; i <= a; i++) cin >> t[i];
		for (int i = 0; i < b; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int ans = 1e9;
		for (int i = 1; i <= a; i++) {
			if (adj[i].size() % 2) ans = min(ans, t[i]);
			else {
				for (int u : adj[i]) {
					ans = min(ans, t[i] + t[u]);
				}
			}
		}
		cout << (b & 1 ? ans : 0) << '\n';
	}
}