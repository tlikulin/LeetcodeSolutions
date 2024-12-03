class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int i : nums) ++counter[i];

        auto myCmp = [](const pair<int, int>& a, const pair<int, int>& b) {return a.second > b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myCmp)> minHeap(myCmp);

        for (auto& entry : counter) {
            minHeap.push(move(entry));
            if (minHeap.size() > k) minHeap.pop();
        }

        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return res;
    }
};