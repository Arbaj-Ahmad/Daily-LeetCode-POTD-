class Solution {
public:
    int totalNumbers(vector<int>& digits) {
         vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        int ans = 0;

        // Step 2: Loop through all possible 3-digit even numbers (100 to 998)
        for (int i = 100; i < 1000; i += 2) {
            int hundreds = i / 100;
            int tens = (i / 10) % 10;
            int ones = i % 10;

            // Step 3: Check if we have the needed digits in our count map
            count[hundreds]--;
            count[tens]--;
            count[ones]--;

            // If none of the counts dropped below zero, we can form this number
            if (count[hundreds] >= 0 && count[tens] >= 0 && count[ones] >= 0) {
                ans++;
            }

            // Step 4: Add the digits back (backtrack) to restore the count map
            count[hundreds]++;
            count[tens]++;
            count[ones]++;
        }

        return ans;
    }
};
        
    