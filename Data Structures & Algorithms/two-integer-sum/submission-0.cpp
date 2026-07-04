class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; //[num,index]
        mp[nums[0]]=0;
        for(int i=1;i<nums.size();i++){
            if(mp.contains(target-nums[i])){
                return {mp[target-nums[i]],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
