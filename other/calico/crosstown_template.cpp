#include <iostream>
#include <vector>

using namespace std;

/**
 * Find the longest distance travelled by any passenger when getting from their
 * starting station to their ending station.
 * 
 * N: the number of passengers
 * M: the number of stations
 * S: list of starting stations for each passenger
 * E: list of ending stations for each passenger
 */
int solve(int N, int M, vector<int> &S, vector<int> &E) {
    int ans = -1;
    for(int i = 0; i < N; i++){
        int dist = E[i] - S[i] >= 0 ? E[i] - S[i] : E[i] - S[i] + M;
        ans = max(ans, dist);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        vector<int> S(N);
        for (int &item : S) {
            cin >> item;
        }
        vector<int> E(N);
        for (int &item : E) {
            cin >> item;
        }
        cout << solve(N, M, S, E) << '\n';
    }
}
