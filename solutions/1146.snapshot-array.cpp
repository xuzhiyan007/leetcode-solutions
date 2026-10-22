class SnapshotArray {
    unordered_map<int, vector<pair<int, int>>> history;
    int cur_snap_id = 0;
public:
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        history[index].push_back(make_pair(cur_snap_id, val));
    }
    
    int snap() {
        return cur_snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto& h = history[index];

        auto it = std::lower_bound(h.begin(), h.end(), make_pair(snap_id + 1, 0)); //pair 的字典序比较特性（先比 first，再比 second）
        int j = it - h.begin() - 1;
        return j >= 0 ? h[j].second : 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
