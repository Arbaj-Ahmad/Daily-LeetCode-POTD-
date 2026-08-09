class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int low = 0;
        int sum = 0;
        int res = INT_MAX;

        for (int high = 0; high < nums.size(); ++high) {
            sum += nums[high];

            while (sum >= target) {
                res = min(res, high - low + 1);
                sum -= nums[low];
                ++low;
            }
            // if (low == high) {
            //     break;
            // }
        }
        if (res == INT_MAX) {
            return 0;
        } else {
            return res;
        }
    }
};
