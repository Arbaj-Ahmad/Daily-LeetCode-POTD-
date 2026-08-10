class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> t(n+1, false);

       t[0]= false; 




        for (int i = 1; i < n + 1; i++) {

            for (int j = 1; j * j <= i; j++) {
                if (t[i - j*j] == false) {
                        t[i] = true;
                        break;
                    }
            }
        }
        return t[n];
    }
};