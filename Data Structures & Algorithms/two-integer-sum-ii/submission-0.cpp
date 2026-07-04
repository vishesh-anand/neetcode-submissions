class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        for(int i=0;i<nums.size();i++){
            if(numToIndex.contains(target-nums[i])){
                return vector<int>{numToIndex[target-nums[i]]+1,i+1};
            }
            numToIndex[nums[i]] = i;
        }
        return vector<int>{};
    }
};
