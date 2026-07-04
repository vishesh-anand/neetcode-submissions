class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int len = temp.size();
        vector<int> result(len,0);
        for(int i=len-2;i>=0;i--){
            int x = i+1;
            while(temp[x]<=temp[i]){
                if(result[x]==0){
                    x=i;
                    break;
                }
                x = x + result[x];
            }
            result[i]=x-i;
        }
        return result;
    }
};
