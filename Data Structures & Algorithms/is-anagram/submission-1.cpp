class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> cntchar;
        for(char c:s){
            cntchar[c]++;
        }
        for(char c:t){
            if(!cntchar.contains(c)){
                return false;
            }
            else{
                cntchar[c]--;
            }
        }
        for(auto const&[key,val]:cntchar ){
            if(val!=0){
                return false;
            }
        }
        return true;
    }
};
