class RangeFreqQuery {
    unordered_map<int, vector<int>> pos;

public:
    int lower_bound(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] >= target) {
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto it = pos.find(value);
        if (it == pos.end()) {
            return 0;
        }

        const vector<int>& nums = it->second;
        int start = lower_bound(nums, left);
        int end = lower_bound(nums, right + 1) -1;

        return end - start + 1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
