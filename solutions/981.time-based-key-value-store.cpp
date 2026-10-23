class TimeMap {
    unordered_map<string, vector<pair<int, string>>> history;
    int timestamp = 0;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        history[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        auto& h = history[key];

        auto it = std::lower_bound(h.begin(), h.end(), make_pair(timestamp + 1, ""));

        int j = it - h.begin() - 1;

        return j >= 0 ? h[j].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
