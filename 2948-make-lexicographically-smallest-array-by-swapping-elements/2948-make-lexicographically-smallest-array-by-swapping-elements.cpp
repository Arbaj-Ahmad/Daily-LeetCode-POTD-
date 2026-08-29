class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sorted_pairs(n);
        for (int i = 0; i < n; i++) {
            sorted_pairs[i] = {nums[i], i};
        }
        sort(sorted_pairs.begin(), sorted_pairs.end());
        vector<deque<int>> groups;
        vector<int> idx_to_group(n);
        for (int i = 0; i < n; i++) {
            if (groups.empty() ||
                sorted_pairs[i].first - sorted_pairs[i - 1].first > limit) {
                groups.push_back(deque<int>());
            }

            groups.back().push_back(sorted_pairs[i].first);
            idx_to_group[sorted_pairs[i].second] = groups.size() - 1;
        }

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            int g_idx = idx_to_group[i];
            result[i] = groups[g_idx].front();
            groups[g_idx].pop_front();
        }

        return result;
    }
};