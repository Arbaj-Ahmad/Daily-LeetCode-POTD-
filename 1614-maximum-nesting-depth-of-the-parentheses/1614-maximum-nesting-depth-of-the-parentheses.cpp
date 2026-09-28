class Solution {
public:
    int maxDepth(string s) {
        int max = 0;
        int curr = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                curr+= 1;
                
                // Keep track of the highest depth seen so far
                if (curr > max) {
                    max = curr;
                }
            } 
            else if (s[i] == ')') {
                curr = curr - 1;
            }
        }

        return max;
    }
};
