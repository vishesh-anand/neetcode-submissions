class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxf = 0;
        int l=0,r=0;
        int ans = 0;
        while(r<s.length()){
            freq[s[r]]++;
            maxf = max(maxf,freq[s[r]]);
            if(r-l+1 - maxf > k){
                freq[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
