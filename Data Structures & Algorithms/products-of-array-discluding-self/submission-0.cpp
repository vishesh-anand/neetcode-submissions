class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> pre(len);
        vector<int> post(len);
        pre[0] = nums[0];
        post[len-1] = nums.back();
        for(int i=1;i<len;i++){
            pre[i]=nums[i]*pre[i-1];
        }
        for(int i=len-2;i>=0;i--){
            post[i]=nums[i]*post[i+1];
        }
        vector<int> res;
        for(int i=0;i<len;i++){
            int out = (i==0?1:pre[i-1])*(i==len-1?1:post[i+1]);
            res.push_back(out);
        }
        return res;
    }
};
