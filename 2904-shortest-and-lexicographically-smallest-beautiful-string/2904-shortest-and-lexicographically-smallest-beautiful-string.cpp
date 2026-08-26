class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int low = 0, high = 0;
        int ones = 0;
        string result = "";
        while (high < n) {
            if (s[high] == '1')
                ones++;
            while (ones > k || s[low] == '0') {
                if (s[low] == '1')
                    ones--;
                low++;
            }

            if (ones == k) {
                string temp = s.substr(low, high - low + 1);
                if (result.empty() || temp.length() < result.length() || (temp.length() == result.length() && temp < result)) {
                    result = temp;

                    
                }
            }
            high++;
        }
        return result;
    }
};
