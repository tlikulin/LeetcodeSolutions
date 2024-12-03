class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++){
            hashmap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++){
            int search = target - nums[i];

            if (hashmap.contains(search) && i!=hashmap[search]) {
                return vector<int> {i, hashmap[search]};
            }

        }
        return {-1, -1};
    }
};