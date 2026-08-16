class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int zeros = 0; //count of remainder 0
        int ones = 0; //count of remainder 1
        int two = 0; //count of remainder 2

        for (int i = 0; i < stones.size(); ++i) {
            int r = stones[i] % 3;
            if (r == 0)
                ++zeros;
            else if (r == 1)
                ++ones;
            else if (r == 2)
                ++two;
        }
        if (zeros % 2 == 0)
            return ones > 0 && two > 0; //check b and c not a and literal 2

        else
            return abs(ones - two) > 2; //check band c , not a and b
    }
};