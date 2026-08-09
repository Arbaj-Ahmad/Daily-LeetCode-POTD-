int dp[101][101];// stones diff
class Solution {
public:
    static int stoneGameII(vector<int>& piles) {
        const int n=piles.size();
        for(int i=0; i<=n; i++)
            memset(dp[i], 0, (n+1)*sizeof(int));
        int suf=0;
        for(int i=n-1; i>=0; i--){
            suf+=piles[i];
            int mN=(n-i+1)>>1;
            // dp[i][m]=suf when m>=(n-i+1)/2
            fill_n(dp[i]+mN, n+1-mN, suf);
            for(int m=1; m<mN; m++){
                int sum=0, xN=m<<1, diff=INT_MIN;
                for(int x=1; x<=xN; x++){
                    sum += piles[i+x-1];
                    diff=max(diff, sum-dp[i+x][max(m, x)]); 
                }
                dp[i][m]=diff;
            }
        }
        int sum=accumulate(piles.begin(), piles.end(), 0);
        return (sum+dp[0][1])>>1;// A=((A+B)+(A-B))/2
    }
};