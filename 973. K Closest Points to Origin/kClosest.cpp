class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmpDist = [] (const vector<int>& p1, const vector<int>& p2) {return p1[0]*p1[0] + p1[1]*p1[1] > p2[0]*p2[0] + p2[1]*p2[1];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmpDist)> minHeap(cmpDist);
        for (const auto& point : points) minHeap.push(point);

        vector<vector<int>> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }

        return res;
    }
};