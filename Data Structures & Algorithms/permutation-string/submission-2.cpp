class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()){
            return false;
        }
        unordered_map <char, int> s1map;
        unordered_map<char, int> s2map;
        for(int i=0;i<s1.length();i++){
            s1map[s1[i]]++;
            s2map[s2[i]]++;
        }
        if(areMapsEqual(s1map,s2map)){
            return true;
        }
        for(int i=s1.length();i<s2.length();i++){
            s2map[s2[i]]++;
            s2map[s2[i-s1.length()]]--;
            if (s2map[s2[i-s1.length()]] == 0) {
                s2map.erase(s2[i-s1.length()]);
            }
            if(areMapsEqual(s1map,s2map)){
                return true;
            }
        }
        return false;
    }

    bool areMapsEqual(const unordered_map<char, int>& map1, const unordered_map<char, int>& map2) {
        // If you expect them to be identical in size
        if (map1.size() != map2.size()) return false; 

        for (const auto& [key, value] : map1) {
            // Use .find() instead of [] to avoid accidental insertions
            auto it = map2.find(key);
            
            if (it == map2.end() || it->second != value) {
                return false;
            }
        }
        return true;
    }
};
