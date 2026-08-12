class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int result = 0;

        for (int maxUnique = 1; maxUnique <= 26; maxUnique++) {
            vector<int> count(26, 0);
            int left = 0, right = 0;
            int unique = 0;       // distinct chars in window
            int countAtLeastK = 0; // distinct chars in window meeting the k threshold

            while (right < n) {
                // Expand window by including s[right]
                int idxR = s[right] - 'a';
                if (count[idxR] == 0) unique++;
                count[idxR]++;
                if (count[idxR] == k) countAtLeastK++;
                right++;

                // Shrink window from left if too many distinct chars
                while (unique > maxUnique) {
                    int idxL = s[left] - 'a';
                    if (count[idxL] == k) countAtLeastK--;
                    count[idxL]--;
                    if (count[idxL] == 0) unique--;
                    left++;
                }

                // Valid window: exactly maxUnique distinct chars, all appearing >= k times
                if (unique == maxUnique && unique == countAtLeastK) {
                    result = max(result, right - left);
                }
            }
        }

        return result;
    }
};