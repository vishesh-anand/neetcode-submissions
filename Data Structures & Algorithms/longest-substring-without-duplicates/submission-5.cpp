class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int l = 0;
        int r = 1;
        unordered_map<char,int> mp;
        int longSub = 1;
        mp[s[0]]=1;
        while(r<s.length()){
            if(mp.contains(s[r])){
                longSub = max(longSub,r-l);
                while(s[l]!=s[r]){
                    mp.erase(s[l]);
                    l++;
                }
                l++;
            }
            mp[s[r]]=1;
            r++;
        }
        return max(longSub,r-l);
    }
};
