class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            if (first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }

        vector<string> ans;
        int last_end = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (i != first[s[i] - 'a']) continue; 

            int end = last[s[i] - 'a'];
            bool valid = true;

            for (int j = i; j <= end; ++j) {
                if (first[s[j] - 'a'] < i) { valid = false; break; } 
                end = max(end, last[s[j] - 'a']);
            }

            if (valid) {
                if (i <= last_end) ans.back() = s.substr(i, end - i + 1);
                else ans.push_back(s.substr(i, end - i + 1)); 
                last_end = end;
            }
        }
        return ans;
    }
};
