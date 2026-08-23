class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int left_sum = 0, right_sum = 0;
        int left_b = 0, right_b = 0;

        // Calculate sums and question mark counts for both halves

        // left sum

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                left_b++;
            } else {
                left_sum += num[i] - '0';
            }
        }
        // right sum
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {

                right_b++;
            } else {
                right_sum += num[i] - '0';
            }
        }

        // If total blank is odd, Alice always wins.
        if ((left_b + right_b) % 2 != 0) {
            return true;
        }

        // Check if Bob can balance the game
        // Equation: 2 * (left_sum - right_sum) == 9 * (right_q - left_q)
        return 2 * (left_sum - right_sum) != 9 * (right_b - left_b);
    }
};