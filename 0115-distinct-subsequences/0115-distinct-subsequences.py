class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        if m < n:
            return 0
        
        dp = [0] * (n + 1)
        dp[n] = 1
        
        for i in range(m - 1, -1, -1):
            for j in range(n):
                if s[i] == t[j]:
                    dp[j] = dp[j + 1] + dp[j]
                    
        return dp[0]
