class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=true;
        }
        int longest = 1;
        for(const auto& pair:mp){
            if(!mp.contains(pair.first - 1)){
                int len = 1;
                int cur = pair.first;
                while(mp.contains(cur+1)){
                    cur++;
                    len++;
                }
                longest = (len > longest) ? len : longest;
            }
        }
        return longest;
    }
};
