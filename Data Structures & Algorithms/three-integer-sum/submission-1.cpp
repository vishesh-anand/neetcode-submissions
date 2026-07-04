class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());

        vector<vector<int>> res;
        for(int i=0;i<sorted_nums.size();i++){
            if(sorted_nums[i]>0){
                break;
            }
            if(i>0 && sorted_nums[i] == sorted_nums[i-1]){
                continue;
            }
            int l = i+1;
            int r = sorted_nums.size()-1;
            
            int target = -1*sorted_nums[i];
            while(l<r){
                if(sorted_nums[l]+sorted_nums[r]>target){
                    r--;
                }
                else if(sorted_nums[l]+sorted_nums[r]<target){
                    l++;
                }
                else{
                    res.push_back({sorted_nums[i],sorted_nums[l],sorted_nums[r]});
                    l++;
                    r--;
                    while (l < r && sorted_nums[l] == sorted_nums[l - 1]) {
                        l++;
                    }
                }
            }
        }

        return res;
    }
};
