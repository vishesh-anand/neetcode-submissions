class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int len = temp.size();
        vector<int> warmIdx(len,-1);
        for(int i=len-2;i>=0;i--){
            int x = i+1;
            while(x>=0 && temp[x]<=temp[i]){
                x = warmIdx[x];
            }
            warmIdx[i]=x;
        }
        vector<int> result(len,0);
        for(int i=0;i<len;i++){
            result[i] = warmIdx[i]==-1?0:warmIdx[i]-i;
        }
        return result;
    }
};
