class Solution {
    unordered_map<int, vector<int>> pos;

public:
    int lower_bound(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans(queries.size());
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        for (auto& [_, vec] : pos) {
            int front = vec.front();
            int last = vec.back();

            vec.insert(vec.begin(), last - n);
            vec.push_back(front + n);
        }

        for (int i = 0; i < queries.size(); i++) { //auto&：表示“按引用遍历”。意思是“直接操作哈希表里原来的数据，不要拷贝一份新的”，这样速度最快。[_, vec]：这是核心！哈希表里的每一个元素其实是一个 pair（键值对），包含 first（键）和 second（值）。
            auto it = pos.find(nums[queries[i]]);

            const vector<int>& vec = it->second;
            if (it->second.size() <= 3) {
                ans[i] = -1;
            } else {
                int idx = lower_bound(vec, queries[i]);

                ans[i] = min(queries[i] - vec[idx - 1], vec[idx + 1] - queries[i]);
            }

        }
        return ans;
    }
};
