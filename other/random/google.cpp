#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;

        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);
        for (const auto& point : points) {
            minHeap.push(point);
        }
        for (int i = 0; i < k; ++i) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
};
