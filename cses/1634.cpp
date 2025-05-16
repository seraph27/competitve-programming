#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int dp[1000001][100];
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int& coin : coins) cin >> coin;
    for (int y = 1; y <= x; y++) {
        for (int i = n - 1; i >= 0; i--) {
            int above = inf, right = inf;
            if (y - coins[i] >= 0) above = dp[y - coins[i]][i];
            if (i + 1 < n) right = dp[y][i + 1];
            dp[y][i] = min(1 + above, right);
        }
    }
    cout << (dp[x][0]==inf ? -1 : dp[x][0]) << "\n";
}
