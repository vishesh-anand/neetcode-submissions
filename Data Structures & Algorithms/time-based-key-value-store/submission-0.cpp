class TimeMap {
    unordered_map<string, map<int, string>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()){
            return "";
        }
        
        auto& timeMap = store[key];

        auto it = timeMap.upper_bound(timestamp);
        
        if(it == timeMap.begin()){
            return "";
        }

        --it;
        return it->second;

    }
};
