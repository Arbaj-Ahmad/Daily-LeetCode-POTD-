class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        unordered_map<int, int> freq; 

        int low = 0, length = 0; 

        for(int high = 0; high < s.size(); high++){

            freq[s[high]]++; 

            while(freq[s[high]] > 2){

                freq[s[low]]--; 
                low++; 
            }

            length = max(length, high - low + 1);
        }

        return length;  
    }
};