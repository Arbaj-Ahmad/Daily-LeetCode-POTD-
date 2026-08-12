class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0 , low = -1;
        unordered_map<int, int > frequency;
        for ( int  high = 0 ; high < nums.size(); high++){
            frequency[nums[high]]++;
            while( frequency[nums[high]]> k){
                low++;
                frequency[nums[low]]--;

            }
            ans = max(ans , high - low);
        }
        return ans;

    }
};