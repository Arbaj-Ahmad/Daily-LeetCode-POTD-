class Solution {
private:
    int fun(int n) {
        int sum = 0;
        while (n != 0) {
            int d = n % 10; // it divide and remaimder can not leave ;

            n = n / 10; // it remove remainder;
            sum = sum + d * d;
        }

        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n, fast = fun(n);

        while (fast != 1) {
            slow = fun(slow);
            fast = fun(fun(fast));
            if (slow == fast && slow!= 1){
                return false;
            }
            
        }
        return true;
    }
};