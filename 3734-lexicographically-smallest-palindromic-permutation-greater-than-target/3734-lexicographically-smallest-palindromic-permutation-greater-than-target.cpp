class Solution {



private:
    int counts[26] = {0};
    string mid_char = "";
    int half_len;
    int n;

    // Helper to fill the remaining slots greedily with the smallest possible characters
    string get_smallest_remaining() {
        string rem = "";
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0) {
                rem.append(counts[i], (char)('a' + i));
            }
        }
        return rem;
    }

    // Constructs the full palindrome from the left half prefix
    string construct_palindrome(const string& left_str) {
        string right_str = left_str;
        reverse(right_str.begin(), right_str.end());
        return left_str + mid_char + right_str;
    }

    // DFS with Backtracking
    string dfs(int idx, bool is_greater, string& current_left, const string& target) {
        if (idx == half_len) {
            string full_pali = construct_palindrome(current_left);
            return (full_pali > target) ? full_pali : "";
        }

        // Case 1: Already safely greater than target prefix, fill remaining characters greedily
        if (is_greater) {
            string rem = get_smallest_remaining();
            return construct_palindrome(current_left + rem);
        }

        char t_char = target[idx];

        // Case 2: Matching/dominating prefix with target
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0) {
                char c = (char)('a' + i);
                if (c >= t_char) {
                    counts[i]--;
                    current_left.push_back(c);

                    string res = dfs(idx + 1, is_greater || (c > t_char), current_left, target);
                    if (!res.empty()) return res; // Bubble up the earliest valid lexical match

                    // Backtrack
                    current_left.pop_back();
                    counts[i]++;
                }
            }
        }
        return "";
    }

public:
    string lexPalindromicPermutation(string s, string target) {
         n = s.size();
        half_len = n / 2;
        int total_counts[26] = {0};
        for (char c : s) {
            total_counts[c - 'a']++;
        }
        int odd_count = 0;
        char odd_val = 0;
        for (int i = 0; i < 26; i++) {
            if (total_counts[i] % 2 != 0) {
                odd_count++;
                odd_val = (char)('a' + i);
            }
            counts[i] = total_counts[i] / 2;
        }
        if (odd_count > 1)
            return "";
        if (odd_count == 1)
            mid_char = string(1, odd_val);

        string current_left = "";
        return dfs(0, false, current_left, target);
    }
};