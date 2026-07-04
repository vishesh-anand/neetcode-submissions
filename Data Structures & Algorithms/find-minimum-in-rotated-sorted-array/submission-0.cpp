class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = nums[0];
        while(l<=r){
            int mid = (l + r)/2;
            if(nums[mid]>=nums[l]){
                ans = min(ans,nums[l]);
                l = mid + 1;
            }
            else if(nums[mid]<nums[r]){
                ans = min(ans,nums[mid]);
                r = mid - 1;
            }
        }
        return ans;
    }
};
