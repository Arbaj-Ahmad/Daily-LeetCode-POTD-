class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for( int i =0; i<nums.size();i++){
            int digit_sm= 0;
            int temp = abs(nums[i]);
            while(temp>0){
                digit_sm+=temp%10;
                temp/=10;

            }
            if(digit_sm ==i){
                return i;
            }
        }
        return -1;
    }
};